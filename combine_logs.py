import re

# regex to capture: get_text_geometry("just sent packet with id: 0", Rectangle((x, y, z), w, h)) | (r, g, b)
log_pattern = re.compile(
    r'get_text_geometry\("(?P<msg>.+?packet with id: (?P<id>\d+))", Rectangle\(\((?P<x>[0-9.eE+-]+), (?P<y>[0-9.eE+-]+), [0-9.eE+-]+\), [0-9.eE+-]+, [0-9.eE+-]+\)\)'
)


def parse_log(path, role):
    """Parse a log file into a list of events."""
    events = []
    with open(path, "r") as f:
        for line in f:
            m = log_pattern.search(line)
            if not m:
                continue
            packet_id = int(m.group("id"))
            x = float(m.group("x"))
            y = float(m.group("y"))
            msg = m.group("msg")

            if "sent" in msg:
                kind = "sent"
            elif "received" in msg:
                kind = "received"
            else:
                continue

            events.append((role, kind, packet_id, (x, y)))
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

    # client → server
    for pid, start in client_sent.items():
        if pid in server_recv:
            end = server_recv[pid]
            color = (0.0, 1.0, 0.0)  # green
        else:
            end = ((start[0] + 0.5) / 2, (start[1] + 0.5) / 2)  # halfway
            color = (1.0, 0.0, 0.0)  # red for lost
        arrows.append((start, end, color))

    # server → client
    for pid, start in server_sent.items():
        if pid in client_recv:
            end = client_recv[pid]
            color = (0.0, 0.5, 1.0)  # blue
        else:
            end = ((start[0] + 0.5) / 2, (start[1] + 0.5) / 2)
            color = (1.0, 0.5, 0.0)  # orange for lost
        arrows.append((start, end, color))

    return arrows


def format_arrow(start, end, color):
    # thinner arrows: stem_thickness=0.01, tip_length=0.02
    return f"generate_2d_arrow(({start[0]}, {start[1]}), ({end[0]}, {end[1]}), 0.001, 0.002) | {color}"


def main():
    client_file = "client/invocations.txt"
    server_file = "server/invocations.txt"
    output_file = "combined_output.txt"

    # parse logs for events
    client_events = parse_log(client_file, "client")
    server_events = parse_log(server_file, "server")
    arrows = pair_packets(client_events, server_events)

    with open(output_file, "w") as out:
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


if __name__ == "__main__":
    main()
