t = int(input())
for x in range(t):
    n, k = map(int, input().split())
    s = input()
    g = 0
    for i in range(n//2):
        if s[i] != s[n-1-i]: g += 1
    y = abs(k-g)
    print('Case #'+ str(x+1) + ': ' + str(y))