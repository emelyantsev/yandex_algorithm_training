line = list(map(int, input().split()))

N = line[0]
M = line[1]

t = []

for i in range(N):
    t.append( list(map(int, input().split())) )


steps = [ ['_' for j in range(M) ]  for i in range(N) ]
sums = [ ['_' for j in range(M) ]  for i in range(N)  ]

for i in range(N):

    for j in range(M):

        if i == 0 and j == 0:
            
            sums[i][j] = t[i][j]
        
        elif i == 0 and j != 0:

            sums[i][j] = t[i][j] + sums[i][j-1]
            steps[i][j] = 'R'

        elif i != 0 and j == 0:

            sums[i][j] = t[i][j] + sums[i-1][j]
            steps[i][j] = 'D'
        else:
            sums[i][j] = t[i][j] + max( sums[i-1][j], sums[i][j-1] )  
            steps[i][j] = 'D' if sums[i-1][j] >= sums[i][j-1] else 'R'

curr = (N-1, M-1)

ans = []

while curr != (0,0):
    ans.append( steps[curr[0]][curr[1]] )
    if steps[curr[0]][curr[1]] == 'R':
        curr = (curr[0], curr[1] - 1)
    else:
        curr = (curr[0]-1, curr[1])

print(sums[-1][-1])

for c in reversed(ans):
    print(c, end=' ')
print()




