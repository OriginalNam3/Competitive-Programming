t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    comments = {i: [] for i in range(n)}
    bakas = []
    sussy = []
    for _ in range(m):
        s = input().split()
        a, b = map(int, s[:2])
        c = s[2] == 'imposter'
        comments[a-1].append([b - 1, c])
        comments[b-1].append([a-1, c])
        if a-1 not in bakas: bakas.append(a-1)
        if a not in sussy: sussy.append(a)
        if b not in sussy: sussy.append(b)

    def search(p, i):
        if p in sus[not i]:
            global cap
            cap = 1
            return
        if p in sus[i]: return
        sus[i].append(p)
        if p in bakas: bakas.remove(p)
        for np, c in comments[p]:
            if c: search(np, not i)
            else: search(np, i)
    cap = 0
    imposters = n - len(sussy)
    while bakas:
        cap = 0
        sus = [[], []]
        search(bakas[0], 0)
        if cap:
            print(-1)
            break
        else:
            imposters += max([len(sussybakas) for sussybakas in sus[:2]])
    if not cap:
        print(imposters)

# 3 2
# 1 3 imposter
# 2 3 crewmate