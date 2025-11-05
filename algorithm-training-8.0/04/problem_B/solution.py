
import bisect

n = int( input() )

taxes = []

for i in range(n):

    line = list( map(int, input().split() ) )

    b, t = line[0], line[1]

    taxes.append( ( b, t) )


m = int(input())

for i in range(m):

    q = int( input() )

    ind = bisect.bisect_left(taxes, q, key=lambda x: x[0] )
    print(q*taxes[ind-1][1])



