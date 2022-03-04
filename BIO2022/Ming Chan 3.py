print('Ming Chan')
print('Tonbridge School')

s, n = input().split(' ')
s = list(s)
p = []
m = [0] * len(s)
a = 'abcdefghijklmnopqrstuvwxyz'
for i in range(len(s)):
    pos = s.index(a[i])
    np = [a[pos].upper()]
    m[pos] = 1
    for j in range(pos):
        if m[j]:
            np.append(a[j].upper())
    p.append(np)

prefs = p[0][:]
for i in range(1, len(p)):
    nprefs = []
    for pref in prefs:
        for x in p[i]:
            nprefs.append(pref + x)
    prefs[:] = nprefs[:]
prefs.sort()
print(prefs[int(n)-1])
