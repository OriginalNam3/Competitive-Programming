m = int(input())

pens = {}

for _ in range(m):
    inp = list(map(int, input().split()))
    i = inp[0]
    print(i)
    inp = inp[1:]
    p, w = tuple(inp[:i]), inp[i:]
    pens[p] = []
    for np in pens:
        o = [i for i in np if i in p]
        if o and len(o) == 2:
            pens[p].append()
