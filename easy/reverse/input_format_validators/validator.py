import sys

line = sys.stdin.readline()

n = int(line)

assert 1 <= n <= 1000

for i in range(n):
    line = sys.stdin.readline()
    assert len(line) > 1

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
