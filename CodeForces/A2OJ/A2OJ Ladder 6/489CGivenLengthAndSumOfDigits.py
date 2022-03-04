m, s = map(int, input().split())
if s == 0:
    if m == 1:
        print(0, 0)
        exit(0)
    print(-1, -1)
    exit(0)
if m * 9 < s:
    print(-1, -1)
    exit(0)


o = [9] * (s // 9)
if s % 9 > 0:
    o += [s % 9] + [0] * (m - (s // 9) - 1)
else:
    o += [0] * (m - (s // 9))
o.reverse()
ro = o[:]
if ro[0] == 0:
    ro[0] = 1
    if ro[-(s // 9) - 1]:
        ro[-(s // 9) - 1] -= 1
    else:
        ro[-(s//9)] -= 1
o.reverse()
print(''.join(map(str, ro)), ''.join(map(str, o)))
