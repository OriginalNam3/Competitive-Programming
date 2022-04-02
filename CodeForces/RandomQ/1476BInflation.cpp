# Problem: B. Inflation
# Contest: Codeforces - Educational Codeforces Round 103 (Rated for Div. 2)
# URL: https://codeforces.com/contest/1476/problem/B
# Memory Limit: 256 MB
# Time Limit: 2000 ms
# 
# Powered by CP Editor (https://cpeditor.org)
 
import math
 
t = int(input())
 
for _ in range(t):
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	sum = a[0]
	ans = 0
	for i in range(1, n):
	   # print(sum, a[i], 100 * a[i]/sum, math.ceil((100 * a[i]-(sum*k))/k))
	    if 100 * a[i]/sum > k:
	    	sum -= ans
	    	nsum = sum
	    	ans = max(ans, math.ceil((100 * a[i]-(nsum*k))/k))
	    	sum += ans
	    sum += a[i]
	print(ans)