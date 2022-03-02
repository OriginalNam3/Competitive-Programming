t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    comments = {}
    teams = []
    cap = False
    for _ in range(m):
        a, b, c = input().split()
        c = c == 'imposter'
        if a-1 not in comments: comments[a-1] = []
        if (b-1, c) not in comments[a-1]: comments[a-1].append((b-1, c))
        if b-1 not in comments: comments[b-1] = []
        if (a-1, c) not in comments[b-1]: comments[b-1].append((b-1, c))

    while comments:
        baka, sussy = comments.popitem()
        q = [(baka, sussy, 0)]
        ct = [[], []]
        while q and not cap:
            for baka, sussy, p in q:
                if baka in not p:
                for sussybaka, o in sussy:
                    if sussybaka in comments: q.append((sussybaka, comments.pop(sussybaka), not p if o else p))
                    else:
                        if sussybaka in ct[p if o else not p]:
                            cap = 1


    imposters = n - len(comments)
    if cap:
        print(-1)
        continue
    print(imposters)

# 1
# 5 2
# 1 2 imposter
# 3 4 imposter
# 3 2
# 1 3 imposter
# 2 3 crewmate