#!/usr/bin/env python3
import sys
import random

sys.setrecursionlimit(1000000)

def gen_graph(method, n, e):
    graph = [ [] for i in range(n) ]
    if method == 'complete':
        for i in range(n):
            for j in range(n):
                if i != j:
                    graph[i].append(j)
    elif method == 'random':
        for i in range(1, n):
            par = random.randint(0, i-1)
            graph[par].append(i)
            graph[i].append(par)
        edges = e - (n - 1)
        for i in range(edges):
            a = random.randint(1, n - 1)
            b = random.randint(0, a - 1)
            while a in graph[b]:
                a = random.randint(1, n - 1)
                b = random.randint(0, a - 1)
            graph[a].append(b)
            graph[b].append(a)
    elif method == 'star':
        for i in range(1, n):
            graph[0].append(i)
            graph[i].append(0)
    else:
        print(method)
        assert False
    return graph

def dfs(method, graph, seen, ans, at):
    ans.append(at)
    if seen[at]:
        return False
    seen[at] = True
    if method == 'invalid1' and random.randint(0, len(graph) - at + 10) == 0:
        visit = random.randint(0, len(graph) - 1)
        dfs(method, graph, seen, ans, visit)
    for v in graph[at]:
        if method == 'early' and random.randint(0, len(graph) - at + 10) == 0:
            break
        if not seen[v]:
            dfs(method, graph, seen, ans, v)
    if len(graph[at]) and method == 'invalid2' and random.randint(0, len(graph)//15) == 0:
        visit = graph[at][0]
        dfs(method, graph, seen, ans, visit)


def gen_dfs(method, graph):
    ans = []
    seen = [False] * len(graph)
    dfs(method, graph, seen, ans, random.randint(0, len(graph) - 1))
    return ans

def gen(method, n, E):
    li = method.split(',')
    method = li[0]
    param = li[1]
    graph = gen_graph(method, n, E)
    e = 0
    for i in graph:
        random.shuffle(i)
        e += len(i)
    e //= 2
    print("{} {}".format(n, e))
    shuf = [i for i in range(n)]
    random.shuffle(shuf)
    for i in range(n):
        for j in graph[i]:
            if shuf[i] < shuf[j]:
                print("{} {}".format(shuf[i], shuf[j]))
    thedfs = gen_dfs(param, graph)
    l = [str(shuf[i]) for i in thedfs]
    print(" ".join(l))

seed = int(sys.argv[1])
method = sys.argv[2]
n = int(sys.argv[3])
e = int(sys.argv[4]) if len(sys.argv) >= 5 else -1

random.seed(seed)

gen(method, n, e)
