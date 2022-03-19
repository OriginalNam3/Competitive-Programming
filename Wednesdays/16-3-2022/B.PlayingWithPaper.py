a, b = map(int, input().split())

c = 0
while a > 0 and b > 0:
    if a > b:
        c += a//b
        a %= b
    else:
        c += b//a
        b %= a

print(c)