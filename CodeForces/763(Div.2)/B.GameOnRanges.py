t = int(input())

for _ in range(t):
    n = int(input())
    d = {i: 0 for i in range(1, n + 1)}
    rs = []
    for _ in range(n):
        l, r = map(int, input().split())
        rs.append([l, r])
        for i in range(l, r+1):
            d[i] += 1
    for i in range(1, n+1):
        for j in range(1, n+1):
            if d[j] == i:
                for l, r in rs:
                    if l <= j <= r:
                        print(l, r, j)
                        rs.remove([l, r])
                        break
    print('\n')
