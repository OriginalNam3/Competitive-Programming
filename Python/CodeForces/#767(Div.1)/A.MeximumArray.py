t = int(input())


def search(na):
    if not na: return []
    for i in range(max(na) + 2):
        if i not in na:
            break
    for j in range(1, len(na)):
        if sum(1 for k in range(i) if k in na[:j + 1]) == i == max(na[:j + 1]) + 1:
            return [i] + search(na[j + 1:])
    return [i]


for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = search(a)
    print(len(b))
    s = ''
    for n in b: s += str(n) + ' '
    print(s)
