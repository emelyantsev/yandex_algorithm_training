
line = list( map( int, input().split() ) )

a, b, S = line[0], line[1], line[2]

l = max(a, b)
r = S + max(a,b)

ans = -1

while l <= r:

    m = (l + r) // 2

    sm = (m-a)*(m-b)

    if sm == S:
        ans = m
        break
    elif sm > S:
        r = m-1
    else:
        l = m+1


print(ans)