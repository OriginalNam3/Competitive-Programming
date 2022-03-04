n, m, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

if n <= m:
    da = {}
    for i in a:
        if i not in da: da[i] = 0
        da[i] += 1
    db = {}
    for i in b:
        if i not in db: db[i] = 0
        db[i] += 1
    s = list(set(a + b))
    s.sort()
    k = len(s)
    p = {i: x for i, x in enumerate(s)}
    ac = bc = 0
    ok = False
    for i in range(1, k + 1):
        if p[k-i] in da:
            ac += da[p[k-i]]
        if p[k-i] in db:
            bc += db[p[k-i]]
        if ac > bc:
            ok = True
            break
    print("YES" if ok else "NO")
else:
    print('YES')
