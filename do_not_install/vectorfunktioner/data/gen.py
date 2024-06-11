import random
import sys

N = int(sys.argv[1])
print(N)
print(' '.join([str(random.randint(1, 1000)) for i in range(N)]))

