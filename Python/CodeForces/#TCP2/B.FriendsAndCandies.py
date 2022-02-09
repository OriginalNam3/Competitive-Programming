t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if sum(a) % n != 0:
        print(-1)
        continue
    avg = sum(a) // n
    c = 0
    for i in a:
        if i > avg:
            c += 1
    print(c)
