t = int(input())

for _ in range(t):
    _ = input()
    a = tuple(map(int, input().split()))
    b = tuple(map(int, input().split()))
    f = tuple(map(int, input().split()))
    print(abs(a[0]-b[0]) + abs(a[1]-b[1]) + 2 if (a[0] == b[0] == f[0] and min(a[1], b[1]) < f[1] < max(a[1], b[1])) or (a[1] == b[1] == f[1] and min(a[0], b[0]) < f[0] < max(a[0], b[0])) else abs(a[0]-b[0]) + abs(a[1]-b[1]))

