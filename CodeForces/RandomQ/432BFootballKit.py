n = int(input())

h = {}
a = {}

for i in range(n):
    x, y = map(int, input().split())
    if x not in h: h[x] = 0
    if y not in a: a[y] = []
    a[y].append(i)
    h[x] += 1

teams = [n - 1 for i in range(n)]

for c in h:
    if c in a:
        for i in a[c]:
            teams[i] += h[c]

for hc in teams:
    print(hc, 2 * n - 2 - hc)
