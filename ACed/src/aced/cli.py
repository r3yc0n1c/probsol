from __future__ import annotations

import json
import traceback
from typing import Annotated

import typer
from rich.console import Console
from rich.table import Table

from aced.platforms.leetcode.client import LeetCodeClient, LeetCodeError
from aced.utils import extract_slug_from_url

app = typer.Typer(
    help="ACed: your local-first competitive programming arsenal.",
    no_args_is_help=True,
)

leetcode_app = typer.Typer(
    help="LeetCode question discovery and metadata.",
    no_args_is_help=True,
)
app.add_typer(leetcode_app, name="lc")

console = Console()


@leetcode_app.command("problems")
def list_problems(
    limit: Annotated[int, typer.Option("--limit", "-n", min=1, max=100)] = 20,
    skip: Annotated[int, typer.Option("--skip", min=0)] = 0,
) -> None:
    """Fetch a page of LeetCode problems."""
    try:
        result = LeetCodeClient().list_problems(limit=limit, skip=skip)
    except (LeetCodeError, ValueError) as exc:
        console.print(f"[red]Error:[/red] {exc}")
        traceback.print_exc()
        raise typer.Exit(code=1) from exc

    table = Table(title="LeetCode Problems")
    table.add_column("#", justify="right", style="dim")
    table.add_column("Title")
    table.add_column("Difficulty")
    table.add_column("Slug")
    table.add_column("Paid", justify="center")

    for problem in result["questions"]:
        table.add_row(
            str(problem.get("frontendQuestionId", "?")),
            str(problem.get("title", "Unknown")),
            str(problem.get("difficulty", "?")),
            str(problem.get("titleSlug", "?")),
            "yes" if problem.get("paidOnly") else "no",
        )

    console.print(table)
    console.print(
        f"Showing {len(result['questions'])} of {result.get('total', '?')} problems."
    )


@leetcode_app.command("problem")
def get_problem(
    title_slug: Annotated[
        str | None, typer.Argument(help="Problem slug, e.g. two-sum")
    ] = None,
    url: Annotated[
        str | None,
        typer.Option("--url", "-u", help="LeetCode problem URL"),
    ] = None,
    create: Annotated[
        bool,
        typer.Option(
            "--create", "-c", help="Create a local file template for the problem"
        ),
    ] = False,
    lang: Annotated[
        str,
        typer.Option(
            "--lang",
            "-l",
            help="Create a local file template for the problem with specific programming language",
        ),
    ] = "python3",
) -> None:
    """Fetch details for one problem and print its JSON."""

    if url:
        extracted = extract_slug_from_url(url)
        if not extracted:
            typer.secho(
                "[X] Error: Invalid LeetCode problem URL structure.",
                fg=typer.colors.RED,
                err=True,
            )
            raise typer.Exit(code=1)
        title_slug = extracted

    if not title_slug:
        typer.secho(
            "[X] Error: Missing required argument. Please provide either a TITLE_SLUG or use the --url option.",
            fg=typer.colors.RED,
            err=True,
        )
        raise typer.Exit(code=1)

    try:
        problem = LeetCodeClient().get_problem(title_slug)
    except (LeetCodeError, ValueError) as exc:
        console.print(f"[red]Error:[/red] {exc}")
        traceback.print_exc()
        raise typer.Exit(code=1) from exc

    if create and lang:
        question_id = problem.get("questionFrontendId")
        filename = f"{question_id}-{title_slug[:12]}.py"

        title = problem.get("title", title_slug)
        _content = problem.get("content")
        code_snippets = problem.get("codeSnippets", [])
        chosen_code_snippet = next(
            (cs["code"] for cs in code_snippets if cs["langSlug"] == lang), None
        )

        # Create a basic solution skeleton structure
        skeleton = (
            f'"""\n[{question_id}] {title}\n\nURL: https://leetcode.com/problems/{title_slug}/\n"""'
            f"\n\n{chosen_code_snippet}"
        )

        with open(filename, "w", encoding="utf-8") as f:
            f.write(skeleton)

        console.print(
            f"[green]Success:[/green] Created template file at [bold]{filename}[/bold]"
        )
    else:
        console.print_json(json.dumps(problem, ensure_ascii=False))


if __name__ == "__main__":
    app()
