t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if sorted(a) == a:
        print(0)
        continue
    if a[n-2] > a[n-1] or a[n-1] < 0:
        print(-1)
        continue
    print(n-2)
    o = []
    for i in range(n-3, -1, -1):
        print(i+1, i + 2, n)
