
line = list(map(int, input().split() ) )

n, x = line[0], line[1]

a = list(map(int, input().split() ) )

ap = [1 if a[0] >= x else 0]

for i in range(1, n):

    ap.append( ap[-1] + ( 1 if a[i] >= x else 0 ) )

m = int(input())

start = 0

for i in range(m):

    line = list(map(int, input().split() ) )

    if line[0] == 1:
        a.append(line[1])
        ap.append( ap[-1] + ( 1 if a[-1] >= x else 0 ) )
    
    elif line[0] == 2:

        start += 1

    else:

        k = line[1]

        if k == 0:
            print(0)
        else:

            cnt = ap[start+k-1] - ( 0 if start == 0 else ap[start-1] )
            print(cnt)

