t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    if k == 0:
        print(1)
        continue
    s = list(input())
    # ns = [''] * n
    # for i in range(n):
    #     ns[-1-i] = s[i]
    # if ns != s:
    #     print(2)
    # else:
    #     print(1)
    for i in range(n//2+1):
        if s[i] != s[-1-i]:
            print(2)
            break
        if i == n//2:
            print(1)
