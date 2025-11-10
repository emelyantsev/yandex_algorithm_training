
n = int(input())

s = list(map(int, input().split()))
a = list(map(int, input().split()))

sa = [ (s[i], a[i] ) for i in range(n) ]

sa.sort()

pref_a = [sa[0][1]]

for i in range(1, n):
    pref_a.append( sa[i][1] + pref_a[-1])


l_diff = 0
r_diff = sum(  [ ( sa[i][0] - sa[0][0] ) * sa[i][1]  for i in range(n) ]  )

best_e = sa[0][0]
best_sum = l_diff + r_diff

for i in range(1, n):

    curr_e = sa[i][0]
    l_diff += pref_a[i-1] * ( curr_e - sa[i-1][0] )
    
    suff_sum = pref_a[n-1] - pref_a[i-1]

    r_diff -= suff_sum * ( curr_e - sa[i-1][0] )

    curr_sum = l_diff + r_diff

    if curr_sum < best_sum:
        best_e = curr_e
        best_sum = curr_sum

print(best_e, best_sum)


