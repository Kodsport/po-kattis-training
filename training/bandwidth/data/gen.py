#!/usr/bin/env python3
import sys
import random

sys.setrecursionlimit(1000000)

def dfs(at, graph, seen, spanning):
    for v in graph[at]:
        if not seen[v]:
            seen[v] = True
            spanning[(at, v)] = True
            dfs(v, graph, seen, spanning)

def random_graph(N, M):
    graph = [ [] for i in range(N) ]
    if N < 500:
        possible_edges = []
        edges = []
        for a in range(1, N):
            par = random.randint(0, a - 1)
            edges.append((a, par))
        for a in range(0,N):
            for b in range(a+1,N):
                if possible_edges not in edges:
                    possible_edges.append((a,b))
        edges = random.sample(possible_edges, M)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        return edges, graph
    else:
        m = 0
        used = {}
        edges = []
        for a in range(1, N):
            par = random.randint(0, a - 1)
            edges.append((a, par))
            used[(a, par)] = True
            m += 1

        while m < M:
            e = random.randrange(0,N*N)
            edge = tuple(sorted((e%N,e//N)))
            if edge[0] != edge[1] and not edge in used:
                m += 1
                edges.append((edge[0], edge[1]))
                graph[edge[0]].append(edge[1])
                graph[edge[1]].append(edge[0])
                used[edge] = True
        return edges, graph

seed = int(sys.argv[-1])
method = sys.argv[1]
n = int(sys.argv[2])
e = int(sys.argv[3])
random.seed(seed)

edges, graph = random_graph(n, e)
seen = [False] * n
spanning = {}
dfs(0, graph, seen, spanning)
print("{} {}".format(n, e))
for a, b in edges:
    if method == 'random':
        cost = random.randint(1, e)
    if method == 'near':
        cost = random.randint(1, n//10+1)
    if method == 'spanning':
        if (a, b) in spanning or (b, a) in spanning:
            cost = 1000
        else:
            cost = 1001
    print("{} {} {}".format(a, b, cost))
