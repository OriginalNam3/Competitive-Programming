t = int(input())
for _ in range(t):
    n, m, rb, cb, rd, cd = map(int, input().split())
    if rb > rd: rb = (n - rb) + (n - rd)
    else: rb = rd - rb
    if cb > cd: cb = (m - cb) + (m - cd)
    else: cb = cd - cb
    print(min(rb, cb))