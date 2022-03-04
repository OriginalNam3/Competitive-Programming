t = int(input())

for _ in range(t):
    s = tuple(map(ord, [a for a in input()]))
    if ord('a') not in s:
        print('NO')
        continue
    r = [s.index(ord('a'))] * 2
    ok = True
    for i in range(ord('a') + 1, ord('a') + len(s)):
        if i not in s:
            ok = False
            break
        p = s.index(i)
        if p == r[0]-1 or p == r[1] + 1:
            r = [min(r[0], p), max(r[1], p)]
        else:
            ok = False
            break
    print('YES' if ok else 'NO')

