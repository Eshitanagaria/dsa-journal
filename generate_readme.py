"""
Scans every notes.md in the repo, reads its metadata block, and
rebuilds the table in README.md between the TABLE_START/TABLE_END markers.

Usage: run this from the repo root after adding/editing a problem.
    python generate_readme.py
"""
import os

README_PATH = "README.md"
START_MARK = "<!-- TABLE_START -->"
END_MARK = "<!-- TABLE_END -->"
SKIP_DIRS = {".git", "__pycache__"}

def parse_frontmatter(text):
    if not text.startswith("---"):
        return None
    parts = text.split("---", 2)
    if len(parts) < 3:
        return None
    meta = {}
    for line in parts[1].strip().splitlines():
        if ":" in line:
            key, val = line.split(":", 1)
            meta[key.strip()] = val.strip()
    return meta

def collect_problems(root="."):
    problems = []
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames[:] = [d for d in dirnames if d not in SKIP_DIRS]
        if "notes.md" in filenames:
            full_path = os.path.join(dirpath, "notes.md")
            with open(full_path, encoding="utf-8") as f:
                meta = parse_frontmatter(f.read())
            if meta and "id" in meta:
                rel_folder = os.path.relpath(dirpath, root).replace("\\", "/")
                problems.append({
                    "id": int(meta.get("id", 0)),
                    "title": meta.get("title", "Untitled"),
                    "difficulty": meta.get("difficulty", "?"),
                    "topic": meta.get("topic", "?"),
                    "folder": rel_folder,
                })
    problems.sort(key=lambda p: p["id"])
    return problems

def build_table(problems):
    rows = ["| # | Title | Difficulty | Topic | Link |", "|---|-------|-----------|-------|------|"]
    for p in problems:
        rows.append(f"| {p['id']} | {p['title']} | {p['difficulty']} | {p['topic']} | [solution]({p['folder']}) |")
    return "\n".join(rows)

def update_readme(table_md):
    with open(README_PATH, encoding="utf-8") as f:
        content = f.read()
    if START_MARK not in content or END_MARK not in content:
        print(f"Couldn't find {START_MARK} / {END_MARK} markers in {README_PATH}.")
        return
    before = content.split(START_MARK)[0]
    after = content.split(END_MARK)[1]
    new_content = before + START_MARK + "\n" + table_md + "\n" + END_MARK + after
    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(new_content)

if __name__ == "__main__":
    problems = collect_problems(".")
    table = build_table(problems)
    update_readme(table)
    easy = sum(1 for p in problems if p["difficulty"].lower() == "easy")
    med = sum(1 for p in problems if p["difficulty"].lower() == "medium")
    hard = sum(1 for p in problems if p["difficulty"].lower() == "hard")
    print(f"README updated. Total: {len(problems)} | Easy: {easy} Medium: {med} Hard: {hard}")
