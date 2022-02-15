t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    m = p[0]
    c = 1
    i = 1
    while i < n:
        if p[i] > m:
            if m < min(p[i:]):
                c += 1
            m = p[i]
        i += 1
    print(c)
