t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    print('YES' if ((b - (c - b)) % a == 0 and (b - (c - b)) > 0) or ((b + (b - a)) % c == 0 and (b + (b - a)) > 0) or ((c + a) % 2 == 0 and ((c + a)//2) % b == 0) else 'NO')