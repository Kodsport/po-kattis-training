import random

n = random.randrange(3, 21)
m = random.randrange(0, 51)

a = random.randrange(m + 1)
b = random.randrange(m - a + 1)
c = m - a - b

print("%d\n%d %d %d" % (n, a, b, c))
