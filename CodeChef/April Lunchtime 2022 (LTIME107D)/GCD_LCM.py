# Problem: Secret Machine Mania
# Contest: CodeChef - April Lunchtime 2022 Division 4(Rated)
# URL: https://www.codechef.com/LTIME107D/problems/GCD_LCM
# Memory Limit: 256 MB
# Time Limit: 1000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

t = int(input())

for _ in range(t):
    x, c = map(int, input().split())
    if c == 1 or x == 1:
        print(1)
        continue
    i = 2
    f = {}
    cx = x
    for i in range(2, 100002):
        if (x == 1): break
        if x % i == 0: 
            if i not in f: f[i] = 0
            while x % i == 0:
                x //= i
                f[i] += 1
        i += 1
    ans = 1
    if (x > 1): f[x] = 1
    for factor in f:
        # print(factor, f[factor])
        ans *= max(factor ** (min(f[factor] % c, c - (f[factor] % c))), 1)
    if not f:
        print(cx)
        continue
    print(ans)