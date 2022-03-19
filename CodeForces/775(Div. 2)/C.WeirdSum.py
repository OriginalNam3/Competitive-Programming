n, m = map(int, input().split())

d = {}

for i in range(n):
    row = list(map(int, input().split()))
    for j in range(m):
        a, b = d.setdefault(row[j], ([], []))
        a.append(i)
        b.append(j)

print(sum(j * (2 * i + 1 - len(l)) for c in d for l in d[c] for i, j in enumerate(sorted(l))))
