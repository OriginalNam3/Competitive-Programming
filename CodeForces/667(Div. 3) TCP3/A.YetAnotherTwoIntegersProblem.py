import math
t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    d = abs(a-b)
    d = math.ceil(d/10)
    print(d)
