t = int(input())

for _ in range(t):
    n = int(input())
    d = {}
    c = {}
    for _ in range(n-1):
        i, j, x, y = map(int, input().split())
        a, b = x, y
        while a != b:
            nb = min(a, b)
            a = max(a, b) - min(a, b)
            b = nb
        x //= a
        y //= a
        print(x, y)
        c[i] = c.setdefault(i, 1) * x * c.setdefault(j, 1)
        for nj in d.setdefault(i, []):
            c[nj] *= x
        c[j] *= c[i] * y
        for ni in d.setdefault(j, []):
            c[ni] *= y
        print(i, c[i], j, c[j])
        d[i].append(j)
        d[j].append(i)
    for i in c:
        print(i, c[i])