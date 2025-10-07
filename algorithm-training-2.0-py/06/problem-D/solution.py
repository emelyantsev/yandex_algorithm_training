line = list(map(int, input().split()))


def getTreesCount(A : int, K : int, B : int, M : int, D : int) -> int :

    ac = ( D // K ) * (K - 1) * A + (D % K) * A
    bc = ( D // M ) * (M - 1) * B + (D % M) * B 

    return ac + bc



A = line[0]
K = line[1]
B = line[2]
M = line[3]
X = line[4]

l = 0
r = X * 2

while True:

    mid = l + (r-l) // 2

    cnt = getTreesCount(A, K, B, M, mid )

    if cnt >= X:

        prev_count = getTreesCount(A, K, B, M, mid-1)

        if prev_count < X:
            print(mid)
            break
        else:
            r = mid - 1
    else:

        l = mid + 1
    



