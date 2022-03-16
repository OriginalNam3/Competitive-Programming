t = int(input())

for _ in range(t):
    n = int(input())
    if n > 19:
        print('NO')
    else:
        print('YES')
        for i in range(n):
            print(3**i, end=' ')
        print()
