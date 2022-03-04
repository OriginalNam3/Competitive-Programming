n, a, b = map(int, input().split())

s = list(map(int, [c for c in input()]))

print(1 if s[a-1] != s[b-1] else 0)
