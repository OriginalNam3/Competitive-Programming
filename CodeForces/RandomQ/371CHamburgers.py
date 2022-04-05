// Problem: C. Hamburgers
// Contest: Codeforces - Codeforces Round #218 (Div. 2)
// URL: https://codeforces.com/problemset/problem/371/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

h = input()
b = h.count('B')
c = h.count('C')
s = h.count('S')
nb, ns, nc = map(int, input().split())
pb, ps, pc = map(int, input().split())
t = int(input())
l = 0
r = 2 ** 128
while l < r-1:
    m = (l+r)//2
    if max(0, b * m - nb) * pb + max(0, s * m - ns) * ps + max(0, c * m - nc) * pc <= t:
        l = m
    else:
        r = m-1
 
if l == r:
    print(l)
    exit(0)
 
if max(0, b * r - nb) * pb + max(0, s * r - ns) * ps + max(0, c * r - nc) * pc <= t:
    print(r)
else:
    print(l)
