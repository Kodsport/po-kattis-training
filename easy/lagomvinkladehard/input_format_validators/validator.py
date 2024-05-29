import re, sys

intreg = "([1-9][0-9]*)"
fullreg = re.compile("^"+intreg+"$")
line = sys.stdin.readline()
assert fullreg.match(line), "Input does not consist of one int"
N = int(line)
assert 1 <= N and N <= 3000, "N out of bounds"
if len(sys.stdin.readline()) != 0:
	print "Garbage input"
	sys.exit(0)
sys.exit(42)
