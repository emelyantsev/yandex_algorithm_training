

N = int( input() )

events = []

for i in range(N):

    line = list(map(int, input().split() ) ) 

    l = line[0]
    r = line[1]

    events.append( (l, -1) )
    events.append( (r, 1) )

events.sort()

count = 0
start = None

total_len = 0

for event in events:

    if event[1] == -1:

        if count == 0:
            count += 1
            start = event[0]
        else:
            count += 1
        
    else:

        count -= 1

        if count == 0:

            assert start != None

            total_len += event[0] - start
            start = None

print(total_len)
