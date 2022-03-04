t = int(input())

for _ in range(t):
    n = int(input())
    while n % 2 == 0:
        n //= 2
    print('NO' if n == 1 else 'YES')