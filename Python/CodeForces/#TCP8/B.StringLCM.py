t = int(input())

for _ in range(t):
    s1 = input()
    s2 = input()
    unit = 'c'
    for i in range(1, min(len(s1), len(s2)) + 1):
        if s1[:i] * (len(s1) // i) == s1:
            unit = s1[:i]
            break
    if unit * (len(s2) // len(unit)) == s2:
        s1 = len(s1) // len(unit)
        s2 = len(s2) // len(unit)
        n1 = s1
        n2 = s2
        while n1 != n2:
            if n1 > n2:
                n1 -= n2
            else:
                n2 -= n1
        print(((s1 * s2)// n1) * unit)
    else:
        print(-1)


