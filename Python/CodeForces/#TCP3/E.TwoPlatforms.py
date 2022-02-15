t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    if n == 1:
        print(1)
        input()
        input()
        continue
    xa = list(map(int, input().split()))
    ya = input()
    allx = list(set(xa))
    if max(allx) - min(allx) <= k:
        print(n)
        continue
    mx = max(xa)
    d = {}
    for x in xa:
        if x in d: d[x] += 1
        else: d[x] = 1
    # print(d)
    saved = [(sum(d[x] for x in range(x, x + k + 1) if x in d), x, x + k + 1) for x in allx]
    savedtwo = [sum(d[x] for x in range(x, x + 2*k + 1) if x in d) for x in allx]
    m = max(saved[i][0] for i in range(len(saved)))
    ind = [saved[i][0] for i in range(len(saved))].index(m)
    nm = max(saved[i][0] for i in range(len(saved)) if saved[i][2] <= saved[ind][1] or saved[i][1] >= saved[ind][2])
    m = max(max(savedtwo), m + nm)
    print(m)
