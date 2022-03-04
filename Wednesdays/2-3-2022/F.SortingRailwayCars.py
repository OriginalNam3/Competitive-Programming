n = int(input())

p = list(map(int, input().split()))
a = [0] * (n+1)
for i in range(n):
    a[p[i]] = a[p[i]-1] + 1
print(n - max(a))