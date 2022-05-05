n = int(input())

h = list(map(int, input().split()))
w = list(map(int, input().split()))
a = 0
for i in range(n):
    l = h[i]
    r = h[i+1]
    b = w[i]
    a += (l+r)*b / 2
if not int(str(a).split('.')[1]):
    print(int(a))
else:
    print(a)