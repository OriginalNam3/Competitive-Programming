t = int(input())
for _ in range(t):
    s = input()
    for c in s:
        if c != '=':
            break
    ok = 1
    for char in s[1:]:
        if char == '=':
            continue
        if char != c:
            ok = 0
            break
    print(c if ok else '?')