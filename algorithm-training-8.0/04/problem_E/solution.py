

line = list( map( int, input().split() ) )

n, m, k = line[0], line[1], line[2]

a = list( map( int, input().split() ) )


events = [ (i, 1) for i in range(n)]

for i in range(m):

    line = list( map( int, input().split() ) )
    l, r = line[0], line[1]

    events.append( (l-1, 0)  )
    events.append( ( r , -1)  )


events.sort()

cur_buses = 0

bus_counts = []

for e in events:

    if e[1] == -1:
        cur_buses -= 1
    elif e[1] == 0:
        cur_buses += 1
    else:
        bus_counts.append( (cur_buses, e[0]) )


bus_counts.sort(key=lambda x : -x[0])


for item in bus_counts:

    if k == 0:
        break

    ind = item[1]

    ki = min(k, a[ind] )
    a[ind] -= ki
    k -= ki

res = 0

for item in bus_counts:

    cnt, ind = item

    res += cnt * a[ind]

print(res)











