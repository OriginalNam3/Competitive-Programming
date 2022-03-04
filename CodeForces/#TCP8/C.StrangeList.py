t = int(input())

for _ in range(t):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    d = {}
    c = sum(a)
    a = [(a[i], 1) for i in range(len(a))]
    i = 0
    q, p = a[i]
    while q % x == 0:
        b = q // x
        a.append((b, p * x))
        c += b * p * x
        i += 1
        q, p = a[i]
    print(c)
