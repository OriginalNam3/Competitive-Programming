print('Ming Chan')
print('Tonbridge School')

h = [[[0 for i in range(6)] for j in range(5)] for k in range(5)]
rpos = [0, 0]
bpos = [5, 24]
h[0][0][0] = 1
h[4][4][5] = -1
h[3][3][2] = -1
di = [[-5, 1, 5, 4, -1, -6], [-4, 1, 6, 5, -1, -5]]
r, b = map(int, input().split())
s, f = map(int, input().split())

if s == f == 0:
    print(0)
    print(0)
    exit()

def skirmish():
    global rpos
    global bpos
    rpos[:] = [(rpos[0] + 1) % 6, (rpos[1] + r) % 25]
    h[rpos[1]//5][rpos[1] % 5][rpos[0]] = 1
    if (rpos[1]//5) % 2 == 1:
        ni = rpos[1] + di[1][rpos[0]]
        if abs((ni % 5) - (rpos[1] % 5)) <= 2 and 0 <= ni <= 24:
            h[ni // 5][ni % 5][(rpos[0] + 3) % 6] = 1
    if (rpos[1]//5) % 2 == 0:
        ni = rpos[1] + di[0][rpos[0]]
        if abs((ni % 5) - (rpos[1] % 5)) <= 2 and 0 <= ni <= 24:
            h[ni // 5][ni % 5][(rpos[0] + 3) % 6] = 1
    # print(ni)
    # for row in h:
    #     print(row)
    # print('\n')
    bpos[:] = [(bpos[0] - 1) % 6, (bpos[1] + b) % 25]
    h[bpos[1] // 5][bpos[1] % 5][bpos[0]] = -1
    if (bpos[1] // 5) % 2 == 1:
        ni = bpos[1] + di[1][bpos[0]]
        if abs((ni % 5) - (bpos[1] % 5)) <= 2 and 0 <= ni <= 24:
            h[ni // 5][ni % 5][(bpos[0] + 3) % 6] = -1
    if (bpos[1] // 5) % 2 == 0:
        ni = bpos[1] + di[0][bpos[0]]
        if abs((ni % 5) - (bpos[1] % 5)) <= 2 and 0 <= ni <= 24:
            h[ni // 5][ni % 5][(bpos[0] + 3) % 6] = -1


if s > 0:
    for _ in range(s-1):
        skirmish()


def count(h):
    rc = 0
    bc = 0
    for x in h:
        for y in x:
            c = sum(y)
            if c > 0: rc += 1
            if c < 0: bc += 1
    return rc, bc, rc - bc


def feud():
    global h
    clst = []
    hlst = []
    for x in range(len(h)):
        for y in range(len(h[x])):
            for z in range(len(h[x][y])):
                if not h[x][y][z]:
                    nh = [[j[:] for j in i] for i in h]
                    nh[x][y][z] = 1
                    if x % 2 == 1:
                        ni = x*5 + y + di[1][z]
                        if abs((ni % 5) - ((x*5+y) % 5)) <= 2 and 0 <= ni <= 24:
                            nh[ni // 5][ni % 5][(z + 3) % 6]  = 1
                    if x % 2 == 0:
                        ni = x*5 + y + di[0][z]
                        if abs((ni % 5) - ((x*5 + y) % 5)) <= 2 and 0 <= ni <= 24:
                            nh[ni // 5][ni % 5][(z + 3) % 6] = 1
                    clst.append(count(nh))
                    hlst.append(nh)
    dlst = [clst[i][2] for i in range(len(clst))]
    dmax = max(dlst)
    ilst = []
    for i in range(len(dlst)):
        if dlst[i] == dmax:
            ilst.append(i)
    hlst = [hlst[i] for i in ilst]
    clst = [clst[i][0] for i in ilst]
    h = [[j[:] for j in i] for i in hlst[clst.index(max(clst))]]
    clst = []
    hlst = []
    for x in range(len(h)):
        for y in range(len(h[x])):
            for z in range(len(h[x][y])):
                if not h[x][y][z]:
                    nh = [[j.copy() for j in i] for i in h]
                    nh[x][y][z] = -1
                    if x % 2 == 1:
                        ni = x * 5 + y + di[1][z]
                        if abs((ni % 5) - ((x * 5 + y) % 5)) < 2 and 0 <= ni <= 24:
                            nh[ni // 5][ni % 5][(z + 3) % 6] = -1
                    if x % 2 == 0:
                        ni = x * 5 + y + di[0][z]
                        if abs((ni % 5) - ((x * 5 + y) % 5)) < 2 and 0 <= ni <= 24:
                            nh[ni // 5][ni % 5][(z + 3) % 6] = -1
                    clst.append(count(nh))
                    hlst.append(nh)
    dlst = [clst[i][2] for i in range(len(clst))]
    dmin = min(dlst)
    ilst = []
    for i in range(len(dlst)):
        if dlst[i] == dmin:
            ilst.append(i)
    hlst = [hlst[i] for i in ilst]
    clst = [clst[i][1] for i in ilst]
    h = [[j[:] for j in i] for i in hlst[clst.index(max(clst))]]


for _ in range(f):
    feud()

print(count(h)[0])
print(count(h)[1])