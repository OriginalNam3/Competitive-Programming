n = int(input())
x = list(map(int, input().split()))
x.sort()

piles = 0
while x:
    b = 0
    piles += 1
    while x:
        for s in range(b, max(x)+1):
            if s in x:
                x.remove(s)
                b += 1
                break
        if x and b > max(x):
            break
print(piles)

