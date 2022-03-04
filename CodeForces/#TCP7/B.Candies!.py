n = int(input())
s = list(map(int, input().split()))
q = int(input())
b = [0] * (len(s) + 1)

for i in range(len(s)):
    b[i+1] = b[i] + s[i]

for _ in range(q):
    l, r = map(int, input().split())
    print((b[r] - b[l-1])//10)
