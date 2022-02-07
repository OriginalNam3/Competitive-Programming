t = int(input())

for _ in range(t):
    n = int(input())
    h = list(map(int, input().split()))
    if h[n-1] == min(h):
        print(min(h))
        continue
    min = -1
    nmin = 0
    hc = h[:]
    while 
    for i in range(2, n):
        d = h[i]//3
        hc[i-2] += 2 * d
        hc[i-1] += d
        hc[i] -= d
