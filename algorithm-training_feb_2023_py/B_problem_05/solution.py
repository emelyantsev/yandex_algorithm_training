
N = int(input())

L = []

for i in range(N):
    L.append( int(input() ) )

res = 0

for i in range(N-1):
    res += min(L[i], L[i+1])

print(res)