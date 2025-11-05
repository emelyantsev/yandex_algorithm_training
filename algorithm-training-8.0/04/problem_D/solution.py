import math
import bisect

n = int( input() )

a = list( map(int, input().split() ) )

pa = [a[0]]

for i in range(1, n):
    pa.append( pa[-1] + a[i] )

best_l = 0
best_r = n-1

best_diff = abs( a[0] - a[n-1] )

curr_sum = 0

for i in range( n-1, 0, -1):

    curr_sum += a[i]
    ind = min( i-1, bisect.bisect_right( pa, curr_sum ) )
    diff = abs(pa[ind] - curr_sum)

    if diff < best_diff:
        best_l = ind
        best_r = i
        best_diff = diff

    if ind > 0:

        diff = abs(pa[ind-1] - curr_sum)

        if diff < best_diff:
            best_l = ind - 1
            best_r = i
            best_diff = diff
    

print( best_diff, best_l + 1, best_r + 1)




         
