from urllib.parse import urlparse


def extract_slug_from_url(url: str) -> str | None:
    """Helper to parse the title slug out of a LeetCode URL."""
    path_parts = urlparse(url).path.strip("/").split("/")
    # LeetCode URLs typically look like: /problems/title-slug/ or /problems/title-slug/description/
    if len(path_parts) >= 2 and path_parts[0] == "problems":
        return path_parts[1]
    return None
