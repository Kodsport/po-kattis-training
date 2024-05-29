import random

N = random.randint(3, 20)
S = random.randint(10, 200)

print("%d %d" % (N, S))

for i in range(N):
    s = random.randint(1, 200)
    p = random.randint(1, 200)
    print("%d %d" % (s, p))
