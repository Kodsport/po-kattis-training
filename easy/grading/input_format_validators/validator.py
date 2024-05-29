import sys

line = sys.stdin.readline()

a, b, c, d, e = [int(x) for x in line.split()]

assert 100 >= a > b > c > d > e >= 0

line = sys.stdin.readline()
x, = [int(x) for x in line.split()]
assert 0 <= x <= 100

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
