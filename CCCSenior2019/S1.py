s = input()
h = s.count('H') % 2
v = s.count('V') % 2

grid = ['1 2', '3 4']
if h: grid = [grid[1], grid[0]]
if v: grid = [grid[i][2] + ' ' + grid[i][0] for i in range(2)]
for row in grid:
    print(row)