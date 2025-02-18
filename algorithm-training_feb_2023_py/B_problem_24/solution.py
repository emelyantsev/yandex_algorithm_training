N = int(input())

l = list(map(int, input().split()))
a = l[0]
b = l[1]
c = l[2]

dp1 = [a]
dp2 = [b]
dp3 = [c]

for i in range(N-1):

    l = list(map(int, input().split()))

    a = l[0]
    b = l[1]
    c = l[2]

    va = [ dp1[-1] + a, dp2[-1] ]
    if i >= 1:
        va.append(dp3[-2])

    best_a = min(va)
    best_b = dp1[-1] + b
    best_c = dp1[-1] + c

    dp1.append(best_a)
    dp2.append(best_b)
    dp3.append(best_c)

print(dp1[-1])