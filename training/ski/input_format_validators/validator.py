import re
import sys

int_re = "(0|[1-9][0-9]*)"

two_int = "^"+ int_re + " " + int_re + "$"

line = sys.stdin.readline()

assert re.match(two_int, line)

n, k = map(int, line.split())
assert 2 <= n <= 500000 and 1 <= k <= 20000

for i in range(n):
    line = sys.stdin.readline()
    assert re.match(two_int, line)
    a, b = map(int, line.split())
    assert 1 <= a <= n and 1 <= b <= n and a != b

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
