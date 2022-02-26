m = int(input())
n = int(input())
k = int(input())

r = []
c = []
o = {}

g = 0

for _ in range(k):
    inp = input().split()
    t, i = inp[0] == 'C', int(inp[1])
    increase = 0
    if t:
        g += m
        c.append(i)
        for j in r:
            if (i, j) not in o:
                o[(i, j)] = 0
                increase -= 1
            else:
                o[(i, j)] = not(o[(i, j)])
            increase += ((o[(i, j)] * 2) - 1)
    else:
        g += n
        r.append(i)
        for j in c:
            if (j, i) not in o:
                o[(j, i)] = 0
                increase -= 1
            else:
                o[(j, i)] = not(o[(j, i)])
            increase += ((o[(j, i)] * 2) - 1) * (len(c)+1)
    g += increase
    print(increase, g)
print(g)

