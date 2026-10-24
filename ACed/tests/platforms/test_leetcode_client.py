import json
from http.client import HTTPResponse
from io import BytesIO
from pathlib import Path
from unittest.mock import Mock, patch
from urllib.error import HTTPError, URLError

from aced.platforms.leetcode.query_template import (
    PROBLEMSET_QUESTION_LIST,
    QUESTION_CONTENT_WITH_EDITOR_DATA,
)
import pytest

from aced.platforms.leetcode.client import (
    ENDPOINT,
    LeetCodeClient,
    LeetCodeError,
    default_query_dir,
)


@pytest.fixture
def client(tmp_path: Path) -> LeetCodeClient:
    return LeetCodeClient(query_dir=tmp_path)


def mock_response(payload: object) -> Mock:
    response = Mock()
    response.read.return_value = json.dumps(payload).encode("utf-8")
    response.__enter__ = Mock(return_value=response)
    response.__exit__ = Mock(return_value=False)
    return response


# ── Initialization ──────────────────────────────────────────────


def test_default_endpoint(client: LeetCodeClient) -> None:
    assert client.endpoint == ENDPOINT
    assert client.timeout == 15.0


def test_custom_endpoint_and_timeout(tmp_path: Path) -> None:
    client = LeetCodeClient(
        query_dir=tmp_path,
        endpoint="https://example.com/graphql",
        timeout=5.0,
    )

    assert client.endpoint == "https://example.com/graphql"
    assert client.timeout == 5.0


# ── GraphQL execution ───────────────────────────────────────────


@patch("aced.platforms.leetcode.client.urlopen")
def test_execute_success(mock_urlopen: Mock, client: LeetCodeClient) -> None:
    expected = {"viewer": {"username": "test-user"}}
    mock_urlopen.return_value = mock_response({"data": expected})

    result = client.execute("query { viewer { username } }")

    assert result == expected
    mock_urlopen.assert_called_once()

    request = mock_urlopen.call_args.args[0]
    assert request.full_url == ENDPOINT
    assert request.method == "POST"
    assert request.get_header("Content-type") == "application/json"
    assert request.get_header("Accept") == "application/json"

    body = json.loads(request.data.decode("utf-8"))
    assert body == {
        "query": "query { viewer { username } }",
        "variables": None,
    }

    assert mock_urlopen.call_args.kwargs["timeout"] == 15.0


@patch("aced.platforms.leetcode.client.urlopen")
def test_execute_passes_variables(mock_urlopen: Mock, client: LeetCodeClient) -> None:
    mock_urlopen.return_value = mock_response({"data": {"result": True}})
    variables = {"limit": 20, "filters": {"difficulty": "EASY"}}

    client.execute("query Example", variables)

    request = mock_urlopen.call_args.args[0]
    body = json.loads(request.data.decode("utf-8"))

    assert body["variables"] == variables


@patch("aced.platforms.leetcode.client.urlopen")
def test_execute_graphql_errors(mock_urlopen: Mock, client: LeetCodeClient) -> None:
    mock_urlopen.return_value = mock_response(
        {"errors": [{"message": "Invalid query"}]}
    )

    with pytest.raises(LeetCodeError, match="GraphQL error: Invalid query"):
        client.execute("invalid query")


@patch("aced.platforms.leetcode.client.urlopen")
def test_execute_multiple_graphql_errors(
    mock_urlopen: Mock, client: LeetCodeClient
) -> None:
    mock_urlopen.return_value = mock_response(
        {
            "errors": [
                {"message": "Unknown field"},
                {"message": "Invalid variable"},
            ]
        }
    )

    with pytest.raises(LeetCodeError, match="Unknown field; Invalid variable"):
        client.execute("query Example")


@patch("aced.platforms.leetcode.client.urlopen")
def test_execute_non_dict_response(mock_urlopen: Mock, client: LeetCodeClient) -> None:
    mock_urlopen.return_value = mock_response(["unexpected"])

    with pytest.raises(LeetCodeError, match="Unexpected GraphQL response format"):
        client.execute("query Example")


@patch("aced.platforms.leetcode.client.urlopen")
def test_execute_missing_data(mock_urlopen: Mock, client: LeetCodeClient) -> None:
    mock_urlopen.return_value = mock_response({"data": None})

    with pytest.raises(LeetCodeError, match="no usable data"):
        client.execute("query Example")


@patch("aced.platforms.leetcode.client.urlopen")
def test_execute_http_error(mock_urlopen: Mock, client: LeetCodeClient) -> None:
    mock_urlopen.side_effect = HTTPError(
        ENDPOINT, 429, "Too Many Requests", {}, BytesIO(b"")
    )

    with pytest.raises(LeetCodeError, match="HTTP 429"):
        client.execute("query Example")


@patch("aced.platforms.leetcode.client.urlopen")
def test_execute_network_error(mock_urlopen: Mock, client: LeetCodeClient) -> None:
    mock_urlopen.side_effect = URLError("connection refused")

    with pytest.raises(LeetCodeError, match="Could not reach LeetCode"):
        client.execute("query Example")


@patch("aced.platforms.leetcode.client.urlopen")
def test_execute_invalid_json(mock_urlopen: Mock, client: LeetCodeClient) -> None:
    response = Mock()
    response.read.return_value = b"not json"
    response.__enter__ = Mock(return_value=response)
    response.__exit__ = Mock(return_value=False)
    mock_urlopen.return_value = response

    with pytest.raises(LeetCodeError, match="invalid JSON"):
        client.execute("query Example")


# ── Problem listing ─────────────────────────────────────────────


def test_list_problems_rejects_zero_limit(client: LeetCodeClient) -> None:
    with pytest.raises(ValueError, match="limit"):
        client.list_problems(limit=0)


def test_list_problems_rejects_limit_above_100(
    client: LeetCodeClient,
) -> None:
    with pytest.raises(ValueError, match="limit"):
        client.list_problems(limit=101)


def test_list_problems_rejects_negative_skip(
    client: LeetCodeClient,
) -> None:
    with pytest.raises(ValueError, match="skip"):
        client.list_problems(skip=-1)


@patch.object(LeetCodeClient, "execute")
def test_list_problems_success(mock_execute: Mock, client: LeetCodeClient) -> None:
    expected = {
        "total": 1,
        "questions": [
            {
                "frontendQuestionId": "1",
                "title": "Two Sum",
                "titleSlug": "two-sum",
                "difficulty": "Easy",
                "paidOnly": False,
            }
        ],
    }
    mock_execute.return_value = {"problemsetQuestionList": expected}

    result = client.list_problems(limit=10, skip=5)

    assert result == expected
    mock_execute.assert_called_once_with(
        PROBLEMSET_QUESTION_LIST,
        {
            "categorySlug": "",
            "limit": 10,
            "skip": 5,
            "filters": {},
        },
    )


@patch.object(LeetCodeClient, "execute")
def test_list_problems_passes_filters(
    mock_execute: Mock, client: LeetCodeClient
) -> None:
    mock_execute.return_value = {
        "problemsetQuestionList": {"total": 0, "questions": []}
    }
    filters = {"difficulty": "EASY"}

    client.list_problems(filters=filters)

    assert mock_execute.call_args.args[1]["filters"] == filters


@patch.object(LeetCodeClient, "execute")
def test_list_problems_missing_result(
    mock_execute: Mock, client: LeetCodeClient
) -> None:
    mock_execute.return_value = {}

    with pytest.raises(LeetCodeError, match="Missing problemsetQuestionList"):
        client.list_problems()


@patch.object(LeetCodeClient, "execute")
def test_list_problems_invalid_questions(
    mock_execute: Mock, client: LeetCodeClient
) -> None:
    mock_execute.return_value = {"problemsetQuestionList": {"questions": None}}

    with pytest.raises(LeetCodeError, match="questions array"):
        client.list_problems()


# ── Individual problem details ──────────────────────────────────


@pytest.mark.parametrize("slug", ["", "arrays/two-sum"])
def test_get_problem_rejects_invalid_slug(client: LeetCodeClient, slug: str) -> None:
    with pytest.raises(ValueError, match="valid problem title slug"):
        client.get_problem(slug)


@patch.object(LeetCodeClient, "execute")
def test_get_problem_success(mock_execute: Mock, client: LeetCodeClient) -> None:
    expected = {
        "title": "Two Sum",
        "titleSlug": "two-sum",
        "content": "<p>Example problem</p>",
    }
    mock_execute.return_value = {"question": expected}

    result = client.get_problem("two-sum")

    assert result == expected
    mock_execute.assert_called_once_with(
        QUESTION_CONTENT_WITH_EDITOR_DATA,
        {"titleSlug": "two-sum"},
    )


@patch.object(LeetCodeClient, "execute")
def test_get_problem_missing_question(
    mock_execute: Mock, client: LeetCodeClient
) -> None:
    mock_execute.return_value = {"question": None}

    with pytest.raises(LeetCodeError, match="No problem details returned"):
        client.get_problem("unknown-problem")
