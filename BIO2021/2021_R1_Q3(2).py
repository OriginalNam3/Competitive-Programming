b = list('ABCDEFGH')


def add(d):
    nd = d[:]
    nb = b[len(d):]
    nd.append(nb.pop(0))
    return nd


def swap(d):
    nd = d[:]
    nd[0] = d[1]
    nd[1] = d[0]
    return nd


def rotate(d):
    nd = d[:]
    temp = nd.pop(0)
    nd.append(temp)
    return nd


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


olst = perm(list('ABCDE'))
print(olst)
n = 0


for o in olst:
    dlst = [[2, ['A', 'B']]]
    c = 1
    for _ in range(5):
        for _ in range(len(dlst)):
            a, d = dlst.pop(0)
            print(a, d)
            if d == o:
                c = 0
                break
            if a > 5:
                n += 1
                c = 0
                break
            if len(d) < 8:
                dlst.append([a + 1, add(d)])
            if len(d) > 1:
                dlst.append([a + 1, swap(d)])
                dlst.append([a + 1, rotate(d)])
print(n)