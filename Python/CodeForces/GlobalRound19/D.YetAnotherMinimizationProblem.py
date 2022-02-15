t = int(input())


def cost(lst):
    c = 0
    for i in range(len(lst)):
        for j in range(i + 1, len(lst)):
            c += (lst[i] + lst[j]) ** 2
    return c

# a = [3, 6]
# b = [2, 7]
# i = 1
# print(abs(cost(a[:i] + [b[i]]) - cost(b[:i] + [a[i]])), abs(cost(a[:i + 1]) - cost(b[:i + 1])))
# print(abs(sum([abs(a[i] - j) for j in a[:i]]) - sum([abs(b[i] - j) for j in b[:i]])), abs(sum([abs(b[i] - j) for j in a[:i]]) - sum([abs(a[i] - j) for j in b[:i]])))
# print(abs(cost(a[:i] + [b[i]]) - cost(b[:i] + [a[i]])) == abs(cost(a[:i + 1]) - cost(b[:i + 1])) and
#                 abs(sum([abs(a[i] - j) for j in a[:i]]) - sum([abs(b[i] - j) for j in b[:i]])) >
#                 abs(sum([abs(b[i] - j) for j in a[:i]]) - sum([abs(a[i] - j) for j in b[:i]])))

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in range(1, n):
        if abs(cost(a[:i] + [b[i]]) - cost(b[:i] + [a[i]])) < abs(cost(a[:i + 1]) - cost(b[:i + 1])):
            c = b[i]
            b[i] = a[i]
            a[i] = c
    print(a, b)
    t = 0
    for i in range(n):
        for j in range(i + 1, n):
            t += (a[i] + a[j]) ** 2 + (b[i] + b[j]) ** 2
    print(t)
