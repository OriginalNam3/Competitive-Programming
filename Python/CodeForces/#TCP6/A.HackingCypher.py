s = input()
a, b = map(int, input().split())
n = len(s)

ok = False
left = [0] * n
left[0] = int(s[0]) % a
for i in range(1, n):
    left[i] = (10 * left[i-1] + int(s[i])) % a

right = [0] * n
right[-1] = int(s[-1]) % b
tenr = 1
for i in range(2, n+1):
    tenr = (tenr * 10) % b
    right[-i] = (right[-i + 1] + (int(s[-i]) * tenr)) % b

print(left, right)

for i in range(0, n - 1):
    if left[i] == 0 and right[i + 1] == 0 and s[i+1] != '0':
        ok = True
        break
print('YES' if ok else 'NO')
if ok:
    print(s[:i+1])
    print(s[i+1:])