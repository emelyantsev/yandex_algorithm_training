
from typing import List
import sys

def is_possible( a : List[int], b : List[int], k : int ) -> bool:
    
    a = a.copy()
    b = b.copy()

    i = 0
    j = 0

    while True:

        if i == len(a):
            break

        if j == len(b) or (j > i and (j - i) > k ):
            return False

        if a[i] == 0:
            i += 1
            continue

        if b[j] == 0 or (i > j and (i - j) > k ):
            j += 1
            continue

        
        pos_cnt = min( a[i], b[j] )

        a[i] -= pos_cnt
        b[j] -= pos_cnt

    return True



n = int(input())

a = list(map(int, input().split()))
b = list(map(int, input().split()))


if sum(b) < sum(a):
    print(-1)
    sys.exit(0)

l = 0
r = n-1

assert is_possible(a, b, r)

best_ans = n - 1

while True:

    if l == r:
        break

    mid = int( (l+r) / 2 )

    if is_possible(a, b, mid):
        r = mid
        best_ans = min(best_ans, mid)        
    else:
        l = mid + 1


print(best_ans)
