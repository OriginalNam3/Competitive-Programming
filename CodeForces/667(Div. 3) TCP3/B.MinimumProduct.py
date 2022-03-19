t = int(input())

for _ in range(t):
    a, b, x, y, n = map(int, input().split())
    # print(max(a - n, x), max(b - (n - (a - max(a - n, x))), y), max(b - n, y), max(a - (n - (b - max(b - n, y))), x))
    print(min(max(a - n, x) * max(b - (n - (a - max(a - n, x))), y), max(b - n, y) * max(a - (n - (b - max(b - n, y))), x)))
