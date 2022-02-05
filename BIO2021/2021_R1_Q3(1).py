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


o = list(input())

dlst = [[2, ['A', 'B']]]
while True:
    a, d = dlst.pop(0)
    if d == o:
        print(a)
        break
    if len(d) < 8:
        if [a+1, add(d)] not in dlst:
            dlst.append([a + 1, add(d)])
    if [a+1, swap(d)] not in dlst:
        dlst.append([a + 1, swap(d)])
    if [a+1, rotate(d)] not in dlst:
        dlst.append([a + 1, rotate(d)])