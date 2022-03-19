t = int(input())


def is_prime(n):
    i = 2
    while i * i < n:
        if n % i == 0:
            return True
    return False


for _ in range(t):
    x, d = map(int, input().split())
    ok = True
    a = x
    for i in range(2):
        if x % d == 0:
            x //= d
        else:
            ok = False
            break
    if not ok:
        print('NO')
        continue
    print(d, x//2)
    ok = False
    for i in range(2, x // 2):
        if i == d:
            continue
        if x % i == 0:
            print('YES')
            ok = True
            break
    if not ok:
        print('NO')
