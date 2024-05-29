import sys


pieces = ['p', 'n', 'k', 'r', 'b', 'q', 'P', 'N', 'K', 'R', 'B', 'Q', '.']

for i in range(8):
    line = sys.stdin.readline()
    print len(line)
    assert len(line) == 9
    for x in line[0:8]:
        assert x in pieces

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
