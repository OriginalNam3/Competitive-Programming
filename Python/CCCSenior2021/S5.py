n, m = map(int, input().split())
r = []
x = []
for _ in range(m):
    i, j, k = map(int, input().split())
    if i not in x: x.append(i)
    if j not in x: x.append(j)
    r.append([i, j, k])

for i, j, k in r:
    f = {}
    r_ = r[:]
    r_.remove([i, j, k])
    for a, b, c in r_:
        if a <= i <= j <= b:
            if k % c != 0:
                print('Impossible')
                exit(0)
        elif a <= i <= b or a <= j <= b:
            if max(k, c) % min(k, c) == 0:
                nf = max(k, c) // min(k, c)
                for factor in f:
                    if max(factor, nf) % min(factor, nf) == 0 and (i <= f[factor][0] <= a <= f[factor][1] <= j <= b or a <= i <= f[factor][0] <= b <= f[factor][1] <= j):
                        print('Impossible')
                        exit(0)
                f[nf] = [max(i, a), min(j, b)]
            else: f[c] = [max(i, a), min(j, b)]

x.sort()
s = [1] * len(x)
mx = {i: x for i, x in enumerate(x)}
for i, j, k in r:
    for y in range(x.index(i), x.index(j)+1):
        if k % s[y] == 0: s[y] *= int(k / s[y])
        elif k % s[y] != 0: s[y] *= k

fs = [s[0]] * (mx[0]-1)
for i in range(len(s)-1):
    fs += [s[i]] * (mx[i+1] - mx[i])
fs += [s[len(s)-1]] * (n - mx[len(s)-1]+1)
print(fs)

# cs = list(map(int, input().split(' ')))
# print(cs)
# if cs == fs:
#     print('Correct')
# w = []
# for i in range(len(fs)):
#     if fs[i] != cs[i]:
#         w.append(i+1)
# for i in w:
#     for a, b, _ in r:
#         if a <= i <= b:
#             print(a, b, _)
#             print(i)


# def gcd(lst):
#     f = []
#     cf = 2
#     while cf < max(lst):
#         print(cf)
#         for i in range(2, cf):
#             if cf % i == 0:
#                 cf += 1
#                 continue
#         c = sum([a % cf for a in lst])
#         if not c:
#             f.append(cf)
#             lst[:] = [a / cf for a in lst]
#             if 1 in lst: break
#         if c: cf += 1
#     return
#
#
#
# lst = []
# print(gcd(lst))