# Problem: B. Equation
# Contest: Codeforces - Codeforces Alpha Round #20 (Codeforces format)
# URL: https://codeforces.com/problemset/problem/20/B
# Memory Limit: 256 MB
# Time Limit: 1000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

a, b, c = map(int, input().split())

if a == 0 and b == 0 and c == 0:
	print(-1)
	exit(0)

if a == 0 and b == 0:
	print(0)
	exit(0)
	
if a == 0 and c == 0:
	print(1)
	print(0)
	exit(0)
	
if a == 0:
	print(1)
	print(-c/b)
	exit(0)
	
d = b*b - 4 * a * c

if d < 0:
	print(0)
	exit(0)

if d == 0:
	print(1)
	print((-b)/(2 * a))
	exit(0)

print(2)
print(min((-b - (d ** 0.5))/(2 * a)), (-b + (d ** 0.5))/(2 * a))
print(max((-b - (d ** 0.5))/(2 * a)), (-b + (d ** 0.5))/(2 * a))