r, d = map(int, input().split())
n = int(input())

r
c = 0
for _ in range(n):
    x, y, nr = map(int, input().split())
    nd = ((x ** 2 + y ** 2) ** 0.5)
    if r - d <= nd - nr <= nd + nr <= r:
        c += 1
print(c)