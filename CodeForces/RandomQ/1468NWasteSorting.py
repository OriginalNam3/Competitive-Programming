t = int(input())

for _ in range(t):
    c = list(map(int, input().split()))
    a = list(map(int, input().split()))
    print('YES' if c[0] >= a[0] and c[1] >= a[1] and c[2] >= a[2] and c[2] - a[2] >= max(0, a[3] - c[0] + a[0]) + max(0, a[4] - c[1] + a[1]) else 'NO')