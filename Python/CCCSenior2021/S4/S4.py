n, w, d = map(int, input().split())
ww = {}
for _ in range(w):
    a, b = map(int, input().split())
    if b not in ww: ww[b] = []
    ww[b].append(a)
ct = {}

def calc_d(c, lt=-1, travelled=[]):
    if c in travelled:
        return
    travelled.append(c)
    ct[c] = lt + 1
    if c in ww:
        for nc in ww[c]:
            calc_d(nc, lt + 1, travelled)

calc_d(n)


s = list(map(int, input().split()))

for _ in range(d):
    x, y = map(int, input().split())
    temp = s[x-1]
    s[x-1] = s[y-1]
    s[y-1] = temp
    maxt = s.index(n)
    tlst = [maxt] + [ct[s[i]] + i for i in range(maxt) if s[i] in ct]
    print(min(tlst))

# 4 3 3
# 1 2
# 3 4
# 4 1
# 1 4 3 2
# 3 4
# 4 2
# 3 2
