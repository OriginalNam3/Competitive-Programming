t = int(input())

for _ in range(t):
    n = int(input())
    if n % 2 == 0:
        for i in range(n//2):
            for j in range(2):
                print('0 ' * (i * 2) + '1 1 ' + '0 ' * (n - (i * 2) - 2))
    else:
        print('1 ' * 2 + '0 ' * (n - 2))
        for i in range(n - 2):
            print('0 ' * i + '1 ' * 3 + '0 ' * (n - 3 - i))
        print('0 ' * (n - 2) + '1 ' * 2)
