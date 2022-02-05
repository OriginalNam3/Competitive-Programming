n, w, d = map(int, input().split())
ww = {}
nww = {}
clst = []
for _ in range(w):
    a, b = map(int, input().split())
    if a in ww: ww[a].append(b)
    else: ww[a] = [b]
    if b == n:
        clst.append(a)
        nww[a] = 1
s = list(map(int, input().split()))

s_ = [e for e in ww]
for e in nww: s_.remove(e)
if w:
    count = 2
    while True:
        nclst = []
        for c in s_:
            for tc in clst:
                if tc in ww[c]:
                    nclst.append(c)
                    s_.remove(c)
                    nww[c] = count
                    break
        if not nclst: break
        count += 1
        clst[:] = nclst[:]

for _ in range(d):
    x, y = map(int, input().split())
    temp = s[x-1]
    s[x-1] = s[y-1]
    s[y-1] = temp
    maxt = s.index(n)
    tlst = [maxt]
    for i in range(maxt):
        if s[i] in nww: tlst.append(i + nww[s[i]])
    print(min(tlst))
