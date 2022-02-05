print('Ming Chan')
print('Tonbridge School')

p = list('EECCGGAAAA')
m = [0] * len(p)
a = 'abcdefghijklmnopqrstuvwxyz'
for i in range(len(p)):
    pos = a.index(p[i].lower())
    print(m)
    for j in range(pos, len(p)):
        if not m[j]:
            m[j] = a[i]
            break
print(m)