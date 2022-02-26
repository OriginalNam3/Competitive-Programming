t = int(input())
for _ in range(t):
    n = int(input())
    graph = {}
    edges = []
    for i in range(n-1):
        u, v = map(int, input().split())
        edges.append((u, v))
        if u not in graph:
            graph[u] = []
        if v not in graph:
            graph[v] = []
        graph[u].append((v, i))
        graph[v].append((u, i))
    ok = True
    for nv in graph:
        if len(graph[nv]) >= 3:
            ok = False
            break
        if len(graph[nv]) == 1:
            u, v, i = nv, graph[nv][0][0], graph[nv][0][1]
    if not ok:
        print(-1)
        continue
    primes = [3, 2]
    p = 0
    weights = [0] * (n-1)
    for _ in range(n-1):
        weights[i] = primes[p]
        p = (p + 1) % 2
        graph[u].remove((v, i))
        graph[v].remove((u, i))
        if not graph[v]:
            break
        u = v
        i = graph[v][0][1]
        v = graph[v][0][0]
    for w in weights:
        print(w)
