#!/usr/bin/python3

n = int(input())
words = input().split()
m = int(input())
dict = {}
for i in range(m):
    a,b=input().split()
    dict[a]=b
print(" ".join(dict[i] for i in words))
