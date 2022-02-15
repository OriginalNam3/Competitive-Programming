t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    f = False
    oa = []
    ea = []
    [oa.append(i) for i in a if i not in oa and i % 2 == 1]
    [ea.append(i) for i in a if i not in ea and i % 2 == 0]
    if sorted(oa) == oa and sorted(ea) == ea:
        print('YES')
    else:
        print('NO')
