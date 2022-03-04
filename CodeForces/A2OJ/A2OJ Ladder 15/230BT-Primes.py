def primes(n):
    is_prime = [True] * n
    is_prime[0] = is_prime[1] = False
    for i in range(2, n):
        if is_prime[i]:
            for j in range(i * i, n, i):
                is_prime[j] = False
    return is_prime


_ = input()
x = list(map(int, input().split()))

p = primes(1000000)
for n in x:
    if n == 4:
        print('YES')
        continue
    if n < 4 or n % 2 == 0:
        print('NO')
        continue
    rn = n ** 0.5
    print('YES' if int(rn) == rn and p[int(rn)] else 'NO')
