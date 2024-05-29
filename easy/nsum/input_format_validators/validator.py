import sys

line = sys.stdin.readline()

n = int(line)
assert 0 <= n <= 10

line = sys.stdin.readline()
x = [int(x) for x in line.split()]
assert len(x) == n

for y in x:
    assert 0 <= y <= 1000

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
