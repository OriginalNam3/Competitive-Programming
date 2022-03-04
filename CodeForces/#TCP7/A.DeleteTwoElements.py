t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    mean = sum(a)/ n
    a = [e - mean for e in a]
    count = {}
    for e in a:
        if e not in count: count[e] = 0
        count[e] += 1
    c = 0
    for i in a:
        count[i] -= 1
        if -i in count:
            c += count[-i]
    print(c)