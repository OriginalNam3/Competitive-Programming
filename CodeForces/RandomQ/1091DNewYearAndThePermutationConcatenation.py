n = int(input())

c = 0
g = 1
for i in range(2, n + 1):
    c += (g - 1)
    c *= i
    g *= i
    g %= 998244353
    c %= 998244353

print((c + g) % 998244353)