t = int(input())

def lowbinarysearch(high, low, x):
    if high == low:
        return high
    mid = (high + low)//2
    if x < a[mid]:
        return binarysearch(low, mid, x)
    if x > a[mid]:
        return binarysearch(mid, high, x)
    if x == a[mid]:
        return mid

for _ in range(t):
    n, l, r = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    c = 0
    for i in range(n):
        ca = a[i+1:]
        mina = l - a[i]
        if mina > 0:
            ni = binarysearch(i, n, mina)
        if mina
