def find(n, flst):
    ilst = []
    for i in range(len(flst)):
        if flst[i] == n:
            ilst.append(i)
    return ilst

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    p = list(input())
    r = []
    for np in range(len(p)):
        if p[np] == 'B':
            if a[np] >= 1:
                r.append([1, min([a[np], n])])
        if p[np] == 'R':
            if a[np] <= n:
                r.append([max([a[np], 1]), n])
    for i in range(1, n+1):
        if not r:
            print('NO')
            break
        ms = [s for s, e in r]
        mins = min(ms)
        if mins <= i:
            me = [r[b][1] for b in find(mins, ms)]
            c = 0
            for d in sorted(me):
                if d >= i:
                    r.remove([mins, d])
                    c = 1
                    break
            if c == 0:
                print('NO')
                break
        else:
            print('NO')
            break
        if i == n:
            print('YES')
            break