N = int(input())

a0 = 1
a1 = 1
a11 = 0

for i in range(N-1):

    a0_ = a0 + a1 + a11
    a1_ = a0
    a11_ = a1

    a0 = a0_
    a1 = a1_
    a11 = a11_

res = a0 + a1 + a11

print(res)