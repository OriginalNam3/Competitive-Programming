t = int(input())

def is_b(s):
    return

for _ in range(t):
    n, m, r, c = map(int, input().split())
    grid = []
    for _ in range(n):
        grid.append([colour == 'B' for colour in input()])
    if grid[r-1][c-1]:
        print(0)
        continue
    if 1 in grid[r-1] + [grid[i][c-1] for i in range(n)]:
        print(1)
        continue
    elif sum(map(sum, grid)) > 0:
        print(2)
        continue
    print(-1)