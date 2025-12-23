#!/usr/bin/python3
n,t=map(int,input().split())
nums=[int(i) for i in input().split()]

def rec(i, t):
    if i == n:
        return t==0
    ways = 0
    ways += rec(i+1,t)
    ways += rec(i+1,t-nums[i])
    return ways

print(100*rec(0,t)/pow(2, n))
