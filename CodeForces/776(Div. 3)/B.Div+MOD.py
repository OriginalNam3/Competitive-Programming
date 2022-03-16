t = int(input())

for _ in range(t):
    l, r, a = map(int, input().split())
    print(max(r//a + r % a, (r//a - 1 + a - 1)) if l <= a * (r//a) - 1 else r//a + r % a)
