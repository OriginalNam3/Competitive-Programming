n, m = map(int, input().split())
ls = []

c = 0

for i in range(n):
    nl = tuple(map(int, input().split()[1:]))
    if not nl:
        c += 1
        continue
    ls.append((i, nl))


def communicate(i, l, v):
    v.append(i)
    for ni, nl in ls:
        if ni not in v and [a for a in l if a in nl]:
            communicate(ni, nl, v)
    return v

if ls:
    c -= 1

while ls:
    c += 1
    b = communicate(ls[0][0], ls[0][1], [])
    ls = [(i, l) for i, l in ls if i not in b]
print(c)
