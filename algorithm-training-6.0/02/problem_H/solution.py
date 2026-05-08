n = int(input())

a = list(map(int, input().split()))


ls = 0
lc = 0

rs = sum( [ a[i]*i for i in range(1, n) ] ) if n > 1 else 0
rc = sum( [ a[i] for i in range(1, n) ] ) if n > 1 else 0

best_ans = ls + rs

for i in range(1, n):

    lc += a[i-1]
    ls += lc

    rs -= rc
    rc -= a[i]

    best_ans = min(best_ans, ls + rs)

print(best_ans)