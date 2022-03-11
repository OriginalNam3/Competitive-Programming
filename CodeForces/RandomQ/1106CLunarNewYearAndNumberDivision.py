n = int(input())
a = list(map(int, input().split()))

a.sort()
s = 0
for i in range(n//2):
    s += (a[-i - 1] + a[i]) ** 2
if n % 2 == 1:
    s -= (a[-i-1] + a[i]) ** 2
    s += (a[-i-1] + a[i] + a[-i-2]) ** 2
print(s)