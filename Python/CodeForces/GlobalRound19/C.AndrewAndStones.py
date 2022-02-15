t = int(input())

for _ in range(t):
    n = int(input())
    n -= 2
    a = list(map(int, input().split()))
    a = a[1:-1]
    if len(a) == 1:
        if a[0] % 2 == 1:
            print(-1)
            continue
        else:
            print(a[0]//2)
            continue
    if not [i for i in a if i > 1]:
        print(-1)
        continue
    v = [i%2 for i in a]
    print((sum(a) + sum(v))//2)


