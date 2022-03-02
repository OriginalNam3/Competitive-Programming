n = int(input())

g = {}
for _ in range(n-1):
    u, v = map(int, input().split())
    if u not in g: g[u] = []
    if v not in g: g[v] = []
    g[u].append(v)
    g[v].append(u)

p = list(map(int, input().split()))
goal = list(map(int, input().split()))
cnt = 0
ng = {i: [] for i in range(1, n + 1)}

q = [(1, 0, [[], []])]
while q:
    u, parity, np = q.pop()
    for i in np[parity]:
        ng[i].append(u)
    np[parity].append(u)
    if u not in g:
        ng[u].append(u)
    for v in g[u]:
        g[v].remove(u)
        q.append((v, not parity, [np[0][:], np[1][:]]))

o = []

def count(u=1):
    global cnt
    if p[u-1] != goal[u-1]:
        o.append(u)
        for i in ng[u]:
            p[i-1] = not p[i-1]
        cnt += 1


for i in range(1, n + 1):
    count(i)
print(cnt)
for i in o:
    print(i)
