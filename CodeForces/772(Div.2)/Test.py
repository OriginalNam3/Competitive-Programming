p = [1, 2, 3, 4]

for i in p:
    if i + 2 in p:
        p.remove(i+2)
    print(i)