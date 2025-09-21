import random
import sys

lim = int(sys.argv[1]) if sys.argv[1] != "-1" else 1000000000
n = random.randrange(1, lim)

print("%d" % (n))
