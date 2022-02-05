n = int(input())
p = []
w = []
d = []

for _ in range(n):
    np, nw, nd = list(map(int, input().split()))
    p.append(np)
    w.append(nw)
    d.append(nd)

mint = -1
for c in range(min(p), max(p)+1):
    p_ = [abs(e-c) for e in p]
    d_ = [0] * len(d)
    for i in range(len(d)):
        if p_[i] > d[i]:
            d_[i] = p_[i] - d[i]
    t = sum(d_[i] * w[i] for i in range(len(w)))
    if mint == -1 or t < mint:
        mint = t
print(mint)