t = int(input())

for _ in range(t):
    n = int(input())
    if n == 1:
        print('YES')
        a = input()
        continue
    a = list(map(int, input().split()))
    oa = [i for i in a if i % 2 == 1]
    ea = [i for i in a if i % 2 == 0]
    if sorted(oa) == oa and sorted(ea) == ea:
        print('YES')
    else:
        print('NO')
