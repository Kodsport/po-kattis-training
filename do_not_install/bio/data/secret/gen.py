import random
m = random.randint(1, 50)
n = random.randint(1, min(100, m * 10 - 1))

while True:
    x = [random.randint(1, 10) for x in range(m)]
    if sum(x) > n:
        break

print "%d %d" % (n, m)
print " ".join([str(tok) for tok in x])
