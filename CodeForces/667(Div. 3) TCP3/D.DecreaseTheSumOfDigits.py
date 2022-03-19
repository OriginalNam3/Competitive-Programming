import math

t = int(input())

for _ in range(t):
    n, s = input().split()
    sdsum = int(s)
    ndsum = sum(map(int, list(n)))
    if ndsum <= sdsum:
        print(0)
        continue
    diff = ndsum - sdsum
    c = 0
    for i in range(len(n)-1, -1, -1):
        c += int(n[i])
        if ndsum - c + 1 <= sdsum:
            p = 10**(len(n)-i)
            if p > int(n):
                print(p - int(n))
                break
            print((((int(n)//p)+1) * p) - int(n))
            break
