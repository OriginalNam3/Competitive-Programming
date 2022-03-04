t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    m = 0
    i = 1
    while i < n-1:
        if a[i] > a[i+1] and a[i] > a[i-1]:
            if i < n-3 and a[i+2] > a[i+1] and a[i+2] > a[i+3]:
                a[i+1] = max(a[i], a[i+2])
                i += 2
            else:
                a[i+1] = a[i]
                i += 1
            m += 1
        i += 1
    print(m)
    for i in a: print(i)