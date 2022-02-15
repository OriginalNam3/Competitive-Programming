def maxv(lst):
    v = 0
    for i in lst:
        if i > 0:
            v += 1
        if i == 0:
            v += 2
    return v


t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    v = 0
    for l in range(1, n+1):
        for i in range(n-l+1):
            subs = a[i:i+l]
            v += maxv(subs)
    print(v)
