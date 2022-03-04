t = int(input())

for _ in range(t):
    n, x, y = map(int, input().split())
    if n == 2:
        print(min(x, y), max(x, y))
        continue
    diff = abs(x-y)
    div = max(diff//n, 1)
    while True:
        if diff % div == 0 and diff//div < n:
            break
        div += 1
    start = max(max(x, y), (min(x, y) % div) + ((n-1) * div))
    for i in range(n):
        if start - div * i == 0:
            print(start + div)
            continue
        print(start - (div * i))
