a, b, c = map(int, input().split())

mod = 998244353

total = 1
for i in range(2, a + b + c + 1):
    total *= i
    if total > mod:
        total %= mod



