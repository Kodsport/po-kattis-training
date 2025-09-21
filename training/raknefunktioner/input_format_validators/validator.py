import sys

line = sys.stdin.readline()

x, y = [int(x) for x in line.split()]

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
