a, b = map(int, input().split())
c, d = map(int, input().split())

for i in range(100):
    for j in range(100):
        if b + i * a == d + j * c:
            print(b + i * a)
            exit(0)
print(-1)