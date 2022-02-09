
def get_factors(n):
    i = 2
    f = []
    while i * i < n:
        if n % i:
            i += 1
        else:
            n //= i
            f.append(i)
    return f

t = int(input())

for _ in range(t):
    