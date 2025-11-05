
n = int(input())

events = []

for i in range(n):

    line = input().split('-')

    t1 = line[0]
    t2 = line[1]

    events.append( (t2, -1, 1)   )
    events.append( (t1, 1, 0) )

m = int(input())

for i in range(m):

    line = input().split('-')

    t1 = line[0]
    t2 = line[1]

    events.append( (t2, -1, 0) )
    events.append( (t1, 1, 1) )


c = [0, 0]

total = 0

events.sort()

for e in events:

    if e[1] == -1:
        c[e[2]] += 1

    else:

        if c[e[2]] == 0:
            total += 1
        else:
            c[e[2]] -= 1

print(total)




