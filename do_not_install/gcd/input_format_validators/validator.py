import sys

line = sys.stdin.readline()

n, m = [int(x) for x in line.split()]

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
