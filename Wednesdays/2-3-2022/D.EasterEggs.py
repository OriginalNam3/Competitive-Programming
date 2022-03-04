n = int(input())

colours = ['R', 'O', 'Y', 'G', 'B', 'I', 'V']

print('BIVROYG', end='')
for i in range(n-7):
    print(colours[i % 4], end='')
