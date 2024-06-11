import sys

line = sys.stdin.readline()

x, y, z = [int(x) for x in line.split()]

assert 0 <= x <= 1000 and 0 <= y <= 1000

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
