n = int(input())

a = []
for i in range(n - (not (n % 2)), 0, -2):
    a.append(i)
for i in range(n - (n % 2), 0, -2):
    a.append(i)

if n == 2:
    a.pop(-1)

print(len(a))
for i in a:
    print(i, end=' ')
