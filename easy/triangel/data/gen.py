import sys,string
from random import randint

N=int(sys.argv[1])
if(N<0):
    print randint(1,-N)
else:
    K=int(sys.argv[2])
    q=[]
    s=0
    for i in range(1000000):
        s+=i
        if(s+K>N): break
        if(s+K>=1): q.append(s)
    print q[randint(0,len(q)-1)]+K
