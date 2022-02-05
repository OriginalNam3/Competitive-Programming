m = int(input())
n = int(input())
k = int(input())
r = []
c = []
g = 0

for _ in range(k):
    t, i = input().split()
    i = int(i)
    if t == 'R':
        if i not in r:
            g += n - 2 * len(c)
            r.append(i)
        else:
            g -= n - 2 * len(c)
            r.remove(i)
    if t == 'C':
        if i not in c:
            g += m - 2 * len(r)
            c.append(i)
        else:
            g -= m - 2 * len(r)
            c.remove(i)
print(g)

# x.sort()
# y.sort()
# mx = {i: j for i, j in enumerate(x)}
# my = {i: j for i, j in enumerate(y)}
#
# grid = [[0] * len(y) for _ in range(len(x))]
# for t, i in o:
#     if t:
#         for j in range(len(grid[i])):
#             grid[i][j] = not grid[i][j]
#     else:
#         for j in range(len(grid)):
#             grid[j][i] = not grid[j][i]
#
# g = 0
# for i in range(len(grid)):
#     for j in range(len(grid[i])):
#         if grid[]
