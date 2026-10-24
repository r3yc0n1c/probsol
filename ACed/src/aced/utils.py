EXTENSION_MAP = {
    "cpp": "cpp",
    "java": "java",
    "python3": "py",
    "python": "py",
    "javascript": "js",
    "typescript": "ts",
    "csharp": "cs",
    "c": "c",
    "golang": "go",
    "kotlin": "kt",
    "swift": "swift",
    "rust": "rs",
    "ruby": "rb",
    "php": "php",
    "dart": "dart",
    "scala": "scala",
    "elixir": "ex",
    "erlang": "erl",
    "racket": "rkt",
}


def extract_slug_from_url(url: str) -> str | None:
    """Helper to parse the title slug out of a LeetCode URL."""
    # LeetCode URLs typically look like: /problems/title-slug/ or /problems/title-slug/description/
    slug = url.split("problems/")[1].split("/")[0]
    return slug


def create_file(question_id: str, title_slug: str, problem: {}, lang: str):
    filename = f"{question_id}-{title_slug[:12]}.{EXTENSION_MAP[lang]}"
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

    return filename
