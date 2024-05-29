import sys

line = sys.stdin.readline()

n, c = [int(x) for x in line.split()]
assert 1 <= n <= 100
assert 1 <= c <= 50

for i in range(n-1):
    line = sys.stdin.readline()
    x = [int(x) for x in line.split()]
    assert len(x) == x[0] + 1
    for j in x[1:]:
        assert j > (i + 1)

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
