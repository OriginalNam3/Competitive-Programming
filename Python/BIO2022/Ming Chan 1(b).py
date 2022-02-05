print('Ming Chan')
print('Tonbridge School')

alpha = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')

def decrypt(a, b):
    i = ((alpha.index(a) + 1) - (alpha.index(b) + 1))
    return alpha[(i-1) % 26]

n = {}

# s = list('OLYMPIAD')
# c = 0
# os = s[:]
# for x in range(208):
#     c += 1
#     for i in range(len(s)-1, 0, -1):
#         s[i] = decrypt(s[i], s[i-1])
#     if s == os:
#         print(s)
#         break


# s = list(input())
# os = s[:]

p = []

for x in alpha:
    nalpha = alpha[:]
    nalpha.remove(x)
    for y in nalpha:
        nalpha_ = nalpha[:]
        nalpha_.remove(y)
        for z in nalpha_:
            p.append([x, y, z])
            print(x, y, z)

print(p)

for s in p:
    c = 0
    os = s[:]
    while True:
        c += 1
        for i in range(len(s)-1, 0, -1):
            s[i] = decrypt(s[i], s[i-1])
        if s == os:
            if c not in n:
                n[c] = 1
            else:
                n[c] += 1
            break
t = 0
for c in n:
    if 999999999999 % c == 0:
        t += n[c]
print(t)

#{52: 7776, 26: 4032, 13: 3744, 4: 24, 2: 24}