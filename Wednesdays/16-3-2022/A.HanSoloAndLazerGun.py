n, x0, y0 = map(int, input().split())


g = []
for _ in range(n):
    x, y = map(int, input().split())
    if x == x0:
        m = 100001
    else:
        m = (y - y0) / (x - x0)
    if m not in g:
        g.append(m)
print(len(g))

