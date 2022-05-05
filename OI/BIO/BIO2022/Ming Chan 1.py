print('Ming Chan')
print('Tonbridge School')

alpha = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')

def decrypt(a, b):
    i = ((alpha.index(a) + 1) - (alpha.index(b) + 1))
    return alpha[(i-1) % 26]

s = list(input())
for i in range(len(s)-1, 0, -1):
    s[i] = decrypt(s[i], s[i-1])

print(''.join(s))
