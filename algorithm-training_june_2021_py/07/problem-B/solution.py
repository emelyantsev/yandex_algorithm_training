N = int(input())

events = []

for i in range(N):

    line = list( map(int, input().split() ) )

    start = line[0]
    finish = start + line[1]

    events.append( (start, 1) )
    events.append( (finish, -1) )

events.sort()

max_count = 0
cur_count = 0

for event in events:

    if event[1] == -1:
        cur_count -= 1
    else:
        cur_count += 1
    
    max_count = max(max_count, cur_count)

print(max_count)