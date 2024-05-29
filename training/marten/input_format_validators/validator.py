import re
import sys

int_regex = "(0|[1-9][0-9]*)"
line_two_int = "^" + int_regex + " " + int_regex + "$"

line = sys.stdin.readline()
assert re.match(line_two_int, line)
n, e = [int(x) for x in line.split()]

assert 1 <= n <= 100000 and 0 <= e <= 300000

adj = [[] for i in range(n)]

for i in range(e):
    line = sys.stdin.readline()
    assert re.match(line_two_int, line)
    a, b = [int(x) for x in line.split()]
    assert 0 <= a < n and 0 <= b < n
    adj[a].append(b)
    adj[b].append(a)

line = sys.stdin.readline()
l = [int(x) for x in line.split()]

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
