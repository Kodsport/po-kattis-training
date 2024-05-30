import sys
import random

n = 200000 # int(sys.argv[1])
q = 10000 # int(sys.argv[2])
for i in range(q):
    print(random.randint(1, n))
