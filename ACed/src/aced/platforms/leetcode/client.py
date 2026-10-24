from __future__ import annotations

import json
import os
from dataclasses import dataclass
from pathlib import Path
from typing import Any
from urllib.error import HTTPError, URLError
from urllib.request import Request, urlopen

from .query_template import *

ENDPOINT = "https://leetcode.com/graphql/"


class LeetCodeError(RuntimeError):
    """Raised when a LeetCode request or response fails."""


@dataclass(frozen=True, slots=True)
class Operation:
    query: str
    variables: dict[str, Any]


class LeetCodeClient:
    """Small standard-library client for LeetCode's GraphQL endpoint."""

    def __init__(
        self,
        endpoint: str = ENDPOINT,
        timeout: float = 15.0,
    ) -> None:
        self.endpoint = endpoint
        self.timeout = timeout

    def execute(
        self,
        query_template: str,
        variables: dict[str, Any] | None = None,
    ) -> dict[str, Any]:
        payload = json.dumps(
            {
                "query": query_template,
                "variables": variables,
            }
        ).encode("utf-8")

        request = Request(
            self.endpoint,
            data=payload,
            headers={
                "Content-Type": "application/json",
                "Accept": "application/json",
                "User-Agent": "ACed/0.1 (personal competitive programming tool)",
            },
            method="POST",
        )

        try:
            with urlopen(request, timeout=self.timeout) as response:
                result = json.loads(response.read().decode("utf-8"))
        except HTTPError as exc:
            raise LeetCodeError(f"LeetCode returned HTTP {exc.code}") from exc
        except (URLError, TimeoutError, OSError) as exc:
            raise LeetCodeError(f"Could not reach LeetCode: {exc}") from exc
        except (UnicodeDecodeError, json.JSONDecodeError) as exc:
            raise LeetCodeError("LeetCode returned invalid JSON") from exc

        if not isinstance(result, dict):
            raise LeetCodeError("Unexpected GraphQL response format")

        errors = result.get("errors")
        if errors:
            messages = [
                str(error.get("message", error))
                if isinstance(error, dict)
                else str(error)
                for error in errors
            ]
            raise LeetCodeError("GraphQL error: " + "; ".join(messages))

        data = result.get("data")
        if not isinstance(data, dict):
            raise LeetCodeError("GraphQL response has no usable data")

        return data

    def list_problems(
        self,
        limit: int = 50,
        skip: int = 0,
        filters: dict[str, Any] | None = None,
    ) -> dict[str, Any]:
        if not 1 <= limit <= 100:
            raise ValueError("limit must be between 1 and 100")
        if skip < 0:
            raise ValueError("skip must be non-negative")

        data = self.execute(
            PROBLEMSET_QUESTION_LIST,
            {
                "categorySlug": "",
                "limit": limit,
                "skip": skip,
                "filters": filters or {},
            },
        )

        result = data.get("problemsetQuestionList")
        if not isinstance(result, dict):
            raise LeetCodeError("Missing problemsetQuestionList in GraphQL response")

        questions = result.get("questions")
        if not isinstance(questions, list):
            raise LeetCodeError("Problem list is missing its questions array")

        return result

    def get_problem(self, title_slug: str) -> dict[str, Any]:
        if not title_slug or "/" in title_slug:
            raise ValueError("Provide a valid problem title slug")

        data = self.execute(
            QUESTION_CONTENT_WITH_EDITOR_DATA,
            {"titleSlug": title_slug},
        )

        question = data.get("question")

        if not isinstance(question, dict):
            raise LeetCodeError(f"No problem details returned for {title_slug!r}")

        return question
