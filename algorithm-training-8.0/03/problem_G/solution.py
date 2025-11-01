from typing import List
from bisect import bisect_left

def read_input():

    n = int(input())
    a = list(map(int, input().split() ) ) 
    a_sorted = sorted(a)

    pref_sums = [a_sorted[0]]

    for i in range(1, n):
        pref_sums.append(pref_sums[-1]+a_sorted[i])

    return n, a, a_sorted, pref_sums

def count_sum(vals_sorted : List[int], pref_sums : List[int], val : int ) -> int: 

    ind = bisect_left( vals_sorted, val )

    lc = ind
    rc = len(vals_sorted) - ind

    res = 0

    if lc > 0:
        res += (lc * val) - pref_sums[ind-1]

    if rc > 0:

        suf_sums_ind  = pref_sums[-1] - ( pref_sums[ind-1] if ind > 0 else 0 )
        res += suf_sums_ind - (rc * val) 

    return res



n, a, a_sorted, pref_sums_a = read_input()
m, b, b_sorted, pref_sums_b = read_input()

res = 0


for i in range(n):

    res += (i+1)*count_sum(b_sorted, pref_sums_b, a[i])

for j in range(m):

    res -= (j+1)*count_sum(a_sorted, pref_sums_a, b[j])


print(res)
