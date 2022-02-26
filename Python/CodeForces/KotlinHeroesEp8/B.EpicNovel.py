t = int(input())

for _ in range(t):
    n = int(input())
    a, va = map(int, input().split())
    c, vc = map(int, input().split())
    b = int(input())

    print(max((vc - (c-b), va)))