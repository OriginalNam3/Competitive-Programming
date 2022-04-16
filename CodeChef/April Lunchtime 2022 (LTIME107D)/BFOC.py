# Problem: Buckets Full of Candies
# Contest: CodeChef - April Lunchtime 2022 Division 4(Rated)
# URL: https://www.codechef.com/LTIME107D/problems/BFOC
# Memory Limit: 256 MB
# Time Limit: 1000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

t = int(input())
for _ in range(t):
    n, m, l = map(int, input().split())
    if n == 0:
        print(m)
        continue
    m %= l + n - 1
    if l <= m < l + n - 1:
        print(0)
    else:
        print(m)