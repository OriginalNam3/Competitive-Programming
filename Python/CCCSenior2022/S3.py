n, m, k = map(int, input().split())

if ((2 * n) - m + 1) * ((n - (n - m + 1) + 1)/2) < k or n > k:
    print(-1)
    exit(0)
while (((2 * n) - m + 1) * ((n - (n - m + 1) + 1)/2) - k) > m:
    m -= 1
# print(m, sum(i for i in range(n-m+1, n+1)) - k)
diff = sum(i for i in range(n-m+1, n+1)) - k
p = [i for i in range(1, m+1)] * (n//m) + [i for i in range(1, n % m + 1)]
print(m, p)
print(diff)
print(((2 * n) - m + 1) * ((n - (n - m + 1) + 1)/2))
i = -1
while diff > 0:
    p[i] = p[i] % m + 1
    diff -= 1
    i -= 1
s = ''
for a in p: s += str(a) + ' '
print(s)
