import re

# Match the entire get_text_geometry("...packet ... id = 0...", Rectangle((x, y, z), w, h)) call.
# - packet\s*:\s* allows 'packet :' or 'packet:'
# - id\s*=\s*(?P<id>\d+) allows 'id = 0' or 'id=0'
# - re.DOTALL so the message can contain newlines
log_pattern = re.compile(
    r'get_text_geometry\(\s*"(?P<msg>.*?packet\s*:\s*.*?id\s*=\s*(?P<id>\d+).*?)"\s*,\s*'
    r"Rectangle\(\(\s*(?P<x>-?[0-9.eE+\-]+)\s*,\s*(?P<y>-?[0-9.eE+\-]+)\s*,\s*[0-9.eE+\-]+\s*\)\s*,\s*"
    r"[0-9.eE+\-]+\s*,\s*[0-9.eE+\-]+\s*\)\)",
    re.DOTALL,
)


def parse_log(path, role):
    """Parse a log file into a list of events.

    This version reads the whole file and finds multi-line get_text_geometry matches.
    """
    events = []
    print(f"[DEBUG] Parsing log: {path} (role={role})")

    with open(path, "r", encoding="utf-8") as f:
        text = f.read()

    matches = list(log_pattern.finditer(text))
    if not matches:
        print(f"[DEBUG] No get_text_geometry matches found in {path}")
        return events

    for m in matches:
        # compute a 1-based line number for where the match starts
        lineno = text.count("\n", 0, m.start()) + 1
        # short snippet so debug doesn't explode if msg is large
        msg_snippet = m.group("msg")[:200].replace("\n", "\\n")
        print(f"[TRACE] Match at approx. line {lineno}: {msg_snippet!r}")

        # show captured groups for debugging
        for k, v in m.groupdict().items():
            # don't print the entire msg in the dict (we already printed a snippet)
            if k == "msg":
                continue
            print(f"    {k} = {v}")

        packet_id = int(m.group("id"))
        x = float(m.group("x"))
        y = float(m.group("y"))
        msg = m.group("msg")

        # normalize case when looking for sent/received
        low = msg.lower()
        if "sent" in low:
            kind = "sent"
        elif "received" in low:
            kind = "received"
        else:
            print(f"[TRACE] ⚠️  No sent/received keyword in msg at line {lineno}")
            continue

        print(
            f"[DEBUG] Parsed event (approx. line {lineno}): role={role}, kind={kind}, id={packet_id}, pos=({x}, {y})"
        )
        events.append((role, kind, packet_id, (x, y)))

    print(f"[DEBUG] Parsed {len(events)} events from {path}")
    return events


def pair_packets(client_events, server_events):
    arrows = []

    client_sent = {pid: pos for role, kind, pid, pos in client_events if kind == "sent"}
    server_recv = {
        pid: pos for role, kind, pid, pos in server_events if kind == "received"
    }
    server_sent = {pid: pos for role, kind, pid, pos in server_events if kind == "sent"}
    client_recv = {
        pid: pos for role, kind, pid, pos in client_events if kind == "received"
    }

    print(f"[DEBUG] Pairing packets:")
    print(f"    client_sent={list(client_sent.keys())}")
    print(f"    server_recv={list(server_recv.keys())}")
    print(f"    server_sent={list(server_sent.keys())}")
    print(f"    client_recv={list(client_recv.keys())}")

    # client → server
    for pid, start in client_sent.items():
        if pid in server_recv:
            end = server_recv[pid]
            color = (0.0, 1.0, 0.0)  # green
            print(
                f"[DEBUG] Arrow client→server OK: pid={pid}, start={start}, end={end}"
            )
        else:
            end = ((start[0] + 0.5) / 2, (start[1] + 0.5) / 2)
            color = (1.0, 0.0, 0.0)  # red
            print(
                f"[DEBUG] Arrow client→server LOST: pid={pid}, start={start}, fake_end={end}"
            )
        arrows.append((start, end, color))

    # server → client
    for pid, start in server_sent.items():
        if pid in client_recv:
            end = client_recv[pid]
            color = (0.0, 0.5, 1.0)  # blue
            print(
                f"[DEBUG] Arrow server→client OK: pid={pid}, start={start}, end={end}"
            )
        else:
            end = ((start[0] + 0.5) / 2, (start[1] + 0.5) / 2)
            color = (1.0, 0.5, 0.0)  # orange
            print(
                f"[DEBUG] Arrow server→client LOST: pid={pid}, start={start}, fake_end={end}"
            )
        arrows.append((start, end, color))

    print(f"[DEBUG] Generated {len(arrows)} arrows total")
    return arrows


def format_arrow(start, end, color):
    # thinner arrows: stem_thickness=0.01, tip_length=0.02
    arrow_str = f"generate_2d_arrow(({start[0]}, {start[1]}), ({end[0]}, {end[1]}), 0.001, 0.002) | {color}"
    print(f"[DEBUG] Formatted arrow: {arrow_str}")
    return arrow_str


def main():
    client_file = "client/invocations.txt"
    server_file = "server/invocations.txt"
    output_file = "combined_output.txt"

    # parse logs for events
    client_events = parse_log(client_file, "client")
    server_events = parse_log(server_file, "server")
    arrows = pair_packets(client_events, server_events)

    with open(output_file, "w") as out:
        print(f"[DEBUG] Writing concatenated logs + arrows to {output_file}")

        # concatenate both input files into output
        with open(client_file, "r") as cf:
            out.write(cf.read())
        out.write("\n")
        with open(server_file, "r") as sf:
            out.write(sf.read())

        # append arrows (no header comment)
        out.write("\n")
        for start, end, color in arrows:
            out.write(format_arrow(start, end, color) + "\n")

    print(f"[DEBUG] Done. Output written to {output_file}")


if __name__ == "__main__":
    main()
