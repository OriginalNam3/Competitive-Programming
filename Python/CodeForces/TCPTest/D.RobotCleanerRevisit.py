t = int(input())
for _ in range(t):
    n, m, rb, cb, rd, cd, p = map(int, input().split())
    t = set([(n - rb) + (n - rd), abs(rd - rb), (m - cb) + (m - cd), abs(cd - cb)])
    t = list(t)
    t = [e for e in t if e < (n-1)*2]
    t.sort()
    p = int(100/p)
    # print(t)
    # print(p)
    # print(t[(p % (len(t)))-1])
    # print(2 * (n-1) * (p//len(t)))
    print(t[(p % (len(t)))-1] + 2 * (n-1) * ((p-1)//len(t)))
