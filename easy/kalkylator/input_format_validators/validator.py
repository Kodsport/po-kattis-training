import sys

line = sys.stdin.readline()

a = set([ chr(x + ord('0')) for x in range(10)])
b = set(['+', '-', '/', '*'])

for i in range(len(line)-1):
    if i%2 == 0:
        assert line[i] in a
    else:
        assert line[i] in b

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
