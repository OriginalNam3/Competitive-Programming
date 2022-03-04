t = int(input())


def search(na):
    if not na: return []
    if 0 not in na: return [0] * len(na)
    i = max(na)+1
    while True:
        for j in range(1, len(na)):
            if sum(1 for k in range(i) if k in na[:j + 1]) == i:
                return [i] + search(na[j + 1:])
        i -= 1


for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = search(a)
    print(len(b))
    s = ''
    for n in b: s += str(n) + ' '
    print(s)
