t = int(input())

for _ in range(t):
    b = [0] * 31
    n = int(input())
    a = list(map(int, input().split()))
    for i in a:
        for p in range(30, -1, -1):
            if i >= 2**p:
                i -= 2**p
                b[p] = 1
    s = ''
    b.reverse()
    for i in b:
        s += str(i)
    print(int(s, 2))

