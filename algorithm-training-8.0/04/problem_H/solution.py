
n = int(input())

a = list( map(int, input().split() ) )

events = []

for i in range(n):

    events.append( (i, 1) )
    events.append( (i + a[i], -1) )

events.sort()

cur_count = 0

ans = []

for e in events:

    if e[1] == 1:
        ans.append(cur_count * a[len(ans)])
        cur_count += 1
    else:
        cur_count -= 1

print(sum(ans))