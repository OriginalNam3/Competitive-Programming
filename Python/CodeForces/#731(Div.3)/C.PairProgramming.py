t = int(input())

for _ in range(t):
    _ = input()
    k, n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    lst = [a, b]
    i = 0
    c = 0
    s = []
    ok = 1
    while c < n + m and ok:
        if not lst[i]:
            i = not i
        ne = lst[i][0]
        if ne > k:
            i = not i
            if not lst[i] or lst[i][0] > k:
                ok = 0
                break
            continue
        if ne == 0:
            k += 1
        c += 1
        s.append(lst[i].pop(0))
    if not ok:
        s = [-1]
    print(' '.join(map(str, s)))
