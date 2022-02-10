
def get_factors(n):
    i = 2
    f = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            f.append(i)
    if n > 1:
        f.append(n)
    return f

t = int(input())

for _ in range(t):
    a, b, k = map(int, input().split())
    if k == 0:
        if a == b: print('YES')
        else: print('NO')
        continue
    af = get_factors(a)
    bf = get_factors(b)
    if k == 1:
        if a != b and ([i for i in bf if i in af] == bf or [i for i in af if i in bf] == af):
            print('YES')
        else:
            print('NO')
        continue
    o = [i for i in af if i in bf]
    if len(af) + len(bf) >= k:
        print('YES')
    else:
        print('NO')