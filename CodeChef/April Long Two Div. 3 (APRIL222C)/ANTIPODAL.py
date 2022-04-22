# Problem: Antipodal Points
# Contest: CodeChef - April Long Two 2022 Division 3 (Rated)
# URL: https://www.codechef.com/APRIL222C/problems/ANTIPODAL
# Memory Limit: 256 MB
# Time Limit: 2000 ms
# Date & Time: 2022-04-22 21:12:04
# 
# Powered by CP Editor (https://cpeditor.org)

t = int(input())
for _ in range(t):
    n = int(input())
    p = []
    for _ in range(n):
        p.append(tuple(map(int, input().split())))
    ans = 0
    for i in range(n):
        d = {}
        for j in range(n):
            if j == i: continue
            if p[i][0] - p[j][0] != 0: m = (p[i][1]-p[j][1])/(p[i][0]-p[j][0])
            else: m = 1e10
            if m not in d:
                d[m] = 0
            d[m] += 1
            if m == 0: m = 1e10
            else:
                if m == 1e10: m = 0
                else:
                    m = -1/m
            if m in d:
                ans += d[m]
            # print(m)
            # print(ans)
        # print(d)
    print(ans)
