t = int(input())

for _ in range(t):
    _ = input()
    n, m = map(int, input().split())
    a = []
    for i in range(m):
        x, w = map(int, input().split())
        a.append((w, x, i + 1))
    a.sort()
    a = a[:2 * n]
    print(sum(w for w, x, i in a))
    pos = [(x, i) for w, x, i in a]
    pos.sort()
    for i in range(n):
        print(pos[i][1], pos[-i - 1][1])
    print()
