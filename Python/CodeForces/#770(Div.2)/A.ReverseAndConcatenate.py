t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    if k == 0:
        s = input()
        print(1)
        continue
    s = list(input())
    for i in range(n//2+1):
        if s[i] != s[-1-i]:
            print(2)
            break
        if i == n//2:
            print(1)
