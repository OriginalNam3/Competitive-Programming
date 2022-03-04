t = int(input())

for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    for l in range(n):
        if p[l] != l + 1:
            break
    if l == n - 1:
        for n in p:
            print(n)
        continue
    if l < n - 1:
        r = p.index(l + 1)
        np = p[l:r+1]
        np.reverse()
        np = p[:l] + np + p[r+1:]
        for n in np:
            print(n)
