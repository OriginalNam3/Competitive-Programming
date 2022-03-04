t = int(input())

for _ in range(t):
    n, p, k = map(int, input().split())
    a = [int(c)-1 for c in input()]
    x, y = map(int, input().split())
    a = a[p - 1:]
    n = n - p + 1
    missing = [0] * (n-k) + a[-k:]
    for i in range(n - k - 1, -1, -1):
        missing[i] = missing[i+k] + a[i]
    missing += [0]
    mint = - missing[0] * x
    for i in range(n):
        nt = (y * i) - missing[i] * x
        if nt < mint:
            mint = nt
    print(mint)
