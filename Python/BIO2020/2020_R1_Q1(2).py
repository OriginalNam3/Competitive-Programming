r = {1: 'I', 2: 'II', 3: 'III', 4: 'IV', 5: 'V'}
rn = [['I', 'V'], ['X', 'L'], ['C', 'D'], ['M']]


def look(s):
    s += ['']
    ns = []
    char = s[0]
    count = 0
    for c in s:
        if c == char:
            count += 1
        else:
            ns += list(r[count])
            ns.append(char)
            char = c
            count = 1
    return ns


for x in range(1, 4000):



ns = s[:]
for _ in range(n):
    ns = look(ns)

a, b = 0, 0
for c in ns:
    if c == 'I':
        a += 1
    if c == 'V':
        b += 1
print(a, b)
