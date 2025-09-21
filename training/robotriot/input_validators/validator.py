#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[0-9]+ [0-9]+\n$', line)
n, m = map(int, line.strip().split())
assert 1 <= n <= 1000
assert 1 <= m <= 1000

for i in range(n):
    line = sys.stdin.readline()
    assert len(line) == m + 1
    assert line[-1] == '\n'
    line = line[:-1]
    for j, c in enumerate(line):
        assert c in {'.','#','X'}

        if i == 0 or i == n - 1 or j == 0 or j == m - 1:
            assert c == '.'

assert sys.stdin.read() == ''

sys.exit(42)
