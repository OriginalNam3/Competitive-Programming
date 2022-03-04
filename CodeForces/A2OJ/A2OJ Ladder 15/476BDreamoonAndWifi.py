s = [(i == '+') * 2 - 1 for i in input()]
r = list(input())
d = 0

for i in s:
    d += i

pd = [0]
for i in range(len(r)):
    npd = []
    if r[i] == '?':
        for nd in pd:
            npd.append(nd + 1)
            npd.append(nd - 1)
        pd = npd
    else:
        for nd in pd:
            npd.append(nd + ((r[i] == '+') * 2) - 1)
        pd = npd
print(pd.count(d)/len(pd))