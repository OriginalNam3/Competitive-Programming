alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'


def is_pat(s):
    if len(s) == 1:
        return True
    for i in range(1, len(s)):
        a = s[:i]
        b = s[i:]
        ax = [alphabet.index(c) for c in a]
        bx = [alphabet.index(c) for c in b]
        ra = [a[i] for i in range(len(a)-1, -1, -1)]
        rb = [b[i] for i in range(len(b)-1, -1, -1)]
        if min(ax) > max(bx) and is_pat(ra) and is_pat(rb):
            return True
    return False


def show(s):
    if is_pat(s):
        print('YES')
    else:
        print('NO')


def perm(s, c=''):
    if len(s) == 1:
        print(c+ s[0])
        return [c + s[0]]
    lst = []
    for i in range(len(s)):
        ns = s.copy()
        ns.pop(i)
        for p in perm(ns, c + s[i]):
            lst.append(p)
    return lst


plst = []

for p in perm(list('CDEFGHIJKLMNOPQRSTUVWXYZ'), 'B'):
    print(p)
    if is_pat(p):
        plst.append(p)
print(len(plst))
# print(p)
# print(len(p))

# s = input()
# s1, s2 = s.split(' ')
# show(s1)
# show(s2)
# show(s1+s2)