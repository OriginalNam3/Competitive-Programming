n, l, r = map(int, input().split())

mins = 0
c = 1
for i in range(l):
    mins += c
    c *= 2
mins += n - l
maxs = 0
c = 1
for i in range(r):
    maxs += c
    c *= 2
c //= 2
maxs += c * (n-r)

print(mins, maxs)