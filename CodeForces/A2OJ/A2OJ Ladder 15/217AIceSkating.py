n = int(input())
coords = []

for _ in range(n):
    nx, ny = map(int, input().split())
    coords.append((nx, ny))


def search(x, y, v):
    v.append((x, y))
    for nx, ny in coords:
        if (nx == x and ny != y) or (nx != x and ny == y):
            if (nx, ny) not in v:
                search(nx, ny, v)
    return v


c = -1
while coords:
    x, y = coords[0]
    c += 1
    visited = search(x, y, [])
    for coord in visited:
        coords.remove(coord)
print(c)
