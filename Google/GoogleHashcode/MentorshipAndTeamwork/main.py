c, p = map(int, input().split())

contrib = {}
skills = {}

for _ in range(c):
    person, n = input().split()
    n = int(n)
    contrib[person] = [0]
    for _ in range(n):
        skill, level = input().split()
        contrib[person].append((skill, int(level)))
        if skill not in skills: skills[skill] = []
        skills[skill].append((int(level), n, person))

projects = {}
a = []

for _ in range(p):
    inputs = input().split()
    project = inputs.pop(0)
    d, s, b, r = map(int, inputs)
    projects[project] = [(d, s, b, r)]
    for _ in range(r):
        skill, level = input().split()
        projects[project].append((skill, int(level)))
    a.append((s - b - d, project, s + b))

a.sort()

c = 0
t = 0
o = ''
while a:
    ok = True
    for s, project, expiry in a:
        if expiry <= t:
            a.remove((s, project, expiry))
    while ok and a:
        _, project, _ = a.pop(-1)
        d, s, b, r = projects[project][0]
        required = projects[project][1:]
        candidates = []
        mentees = []
        s = ''
        for skill, rlevel in required:
            goodppl = sorted([(level, noskills, name) for level, noskills, name in skills[skill] if contrib[name][0] <= t and level >= rlevel and name not in candidates])
            mentees.append(sorted([(level, noskills, name) for level, noskills, name in skills[skill] if contrib[name][0] <= t and level == rlevel-1 and name not in candidates]))
            if not goodppl:
                ok = False
                break
            candidates.append(goodppl[0][2])
        if ok:
            o += project + '\n'
            c += 1
            for name in candidates:

                contrib[name][0] = t + d
                o += name + ' '
            o += '\n'
        # print(project, candidates, required)
    t += 1
print(c, '\n', o)

            # candidates.append(sorted([(level, noskills, name) for level, noskills, name in skills[skill] if level >= rlevel])[0])

