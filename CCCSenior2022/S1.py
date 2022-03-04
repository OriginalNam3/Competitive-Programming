n = int(input())

print((n//4 - n%4)//5 + 1 if n//4 >= n%4 else 0)