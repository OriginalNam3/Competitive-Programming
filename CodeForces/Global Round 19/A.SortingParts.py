t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n-1):
        if a[i] > a[i+1]:
            print('YES')
            break
        if i == n-2:
            print('NO')
