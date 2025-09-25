import re
import subprocess

brace_re = re.compile(r"\{.*\}$")  # still assumes object at end of msg


def transform(msg: str) -> str:
    match = brace_re.search(msg)
    if not match:
        return msg

    brace_obj = match.group(0)

    # wrap in quotes inside the argument
    arg = f'format_nested_brace_string_recursive("{brace_obj}")'
    cmd = ["tbx_utils", arg]

    try:
        result = subprocess.run(
            cmd,
            capture_output=True,
            text=True,
            check=True,
        )
        formatted = result.stdout.strip()

        # escape newlines so they're literal "\n" in the string
        formatted_escaped = formatted.replace("\n", "\\n")

        return msg[: match.start()] + "\\n" + formatted_escaped
    except subprocess.CalledProcessError:
        return msg
