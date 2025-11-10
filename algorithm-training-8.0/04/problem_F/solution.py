line = list(map(int, input().split()))

n, m, x = line[0], line[1], line[2]

events = []

for i in range(n):

    line = list(map(int, input().split()))

    a, b, v = line[0], line[1], line[2]

    if a < b:

        if x >= b:

            t1 = (x - b) / v
            t2 = (x - a) / v
            events.append( (t1, -1, i) )
            events.append( (t2, 0, i ))
        elif x >= a:

            t2 = (x - a) / v
            events.append( (0, -1, i) )
            events.append( (t2, 0, i ))
        else:
            pass
    else:

        if x <= b:

            t1 = (b - x) / v
            t2 = (a - x) / v
            events.append( (t1, -1, i) )
            events.append( (t2, 0, i ))
        elif x <= a:

            t2 = (a - x) / v
            events.append( (0, -1, i) )
            events.append( (t2, 0, i ))
        else:
            pass

line = list(map(int, input().split()))

for i, t in enumerate(line):

    events.append( (t, 1, i) )

events.sort()

cur_count = 0

ans = [-1 for i in range(m)]

q = []

for e in events:

    if e[1] == -1:
        cur_count += 1
    elif e[1] == 0:
        cur_count -= 1

        if cur_count == 0:

            for qi in q:
                ans[qi] = e[0]
        
            q.clear()

    else:

        if cur_count > 0:
            q.append(e[2])
        else:
            ans[e[2]] = e[0]


for ai in  ans:
    assert ai != -1
    print(f"{ai:.10f}")

