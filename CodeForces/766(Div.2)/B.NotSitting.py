t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    lst = []
    for i in range(n-1):
        for j in range(m-1):
            lst.append(n - i - 1 + m - j + 1)
    lst.sort()
    for e in lst:
        print(e)