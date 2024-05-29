import random

N = random.randint(3, 20)
S = random.randint(10, 200)

print("%d %d" % (N, S))

ratio = random.random();

for i in range(N):
    s = random.randint(1, 200)
    p = round((ratio + random.random()/70.0 * random.randint(-5, 5)) * s)
    print("%d %d" % (s, p))
