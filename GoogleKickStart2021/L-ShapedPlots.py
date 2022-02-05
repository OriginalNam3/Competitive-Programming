t = int(input())

# def find(r, c, l):
#     for i in range(r)

for x in range(t):
    r, c = map(int, input().split())
    grid = []
    for _ in range(r):
        col = list(map(int, input().split()))
        grid.append(col)
    y = 0
    # for l in range(2, r):
    #     if l > 2 and l%2 == 0:
    #         for i in range(r):
    #             for j in range(c):
    #                 if 0 <= i + l <= r:

    # hs = [[], []]
    # vs = [[], []]
    # for l in range(2, c+1):
    #     ns = []
    #     for i in range(r):
    #         for j in range(c-l+1):
    #             if 0 not in grid[i][j:j+l]:
    #                 ns.append([i, [j, j + l-1]])
    #     vs.append(ns)
    # for l in range(2, r+1):
    #     ns = []
    #     for i in range(r-l+1):
    #         for j in range(c):
    #             if 0 not in [grid[i+dl][j] for dl in range(l)]:
    #                 ns.append([j, [i, i + l-1]])
    #     hs.append(ns)
    # slst = []
    # for i in range(len(vs)):
    #     d = i * 2
    #     if d <= r:
    #         for oi, [sj, ej] in vs[i]:
    #             for nj, [si, ei] in hs[d]:
    #                 if (nj == sj or nj == ej) and (oi == si or oi == ei):
    #                     slst.append([[sj, ej], [si, ei]])
    #                     y += 1
    # for i in range(len(hs)):
    #     d = i * 2
    #     if d <= c:
    #         for oj, [si, ei] in hs[i]:
    #             for ni, [sj, ej] in vs[d]:
    #                 if (ni == si or ni == ei) and (oj == sj or oj == ej):
    #                     slst.append([[sj, ej], [si, ei]])
    #                     y += 1
    print('Case #' + str(x+1) + ': ' + str(y))
