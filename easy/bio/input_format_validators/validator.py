import sys

line = sys.stdin.readline()

n, m = [int(x) for x in line.split()]
assert 1 <= n <= 100
assert 1 <= m <= 50

line = sys.stdin.readline()
x = [int(x) for x in line.split()]
assert len(x) == m
assert sum(x) > n

for y in x:
    assert 1 <= y <= 10

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
