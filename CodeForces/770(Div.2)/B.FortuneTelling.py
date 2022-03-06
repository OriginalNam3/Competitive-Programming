t = int(input())

for _ in range(t):
    n, x, y = map(int, input().split())
    a = list(map(int, input().split()))
    print('Alice' if (x % 2) ^ (sum(a) % 2) == y % 2 else 'Bob')
