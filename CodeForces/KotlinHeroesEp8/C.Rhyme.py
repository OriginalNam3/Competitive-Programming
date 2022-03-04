t = int(input())

for _ in range(t):
    n = int(input())
    r = [[], []]
    for _ in range(n):
        s, t, m = input().split()
        m = int(m)
        r[m].append((s, t))
    k = []
    a = 0
    if r[0]:
        while r[0]:
            a += 1
            c = 0
            for s, t in r[0]:
                if len(s) < a or len(t) < a:
                    r[0].remove((s, t))
                elif s[-a] != t[-a]:
                    c += 1
                    r[0].remove((s, t))
    i = 0
    ok = True
    while ok:
        i += 1
        for s, t in r[1]:
            if len(s) < i or len(t) < i:
                ok = False
                break
            if s[-i] != t[-i]:
                ok = False
                break
    print(max(i - a, 0))
    for j in range(a, i):
        print(j, end=' ')
    if i - a > 0: print('')