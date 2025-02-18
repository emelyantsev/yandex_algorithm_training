line = list(map(int, input().split() ))

N = line[0]
M = line[1]

dp = [ [0 for j in range(M) ] for i in range(N) ]

dp[0][0] = 1

for i in range(N):
    for j in range(M):

        if i-2 >= 0 and j-1 >= 0:
            dp[i][j] += dp[i-2][j-1]

        if i-1 >= 0 and j-2 >= 0:
            dp[i][j] += dp[i-1][j-2]
    
print(dp[-1][-1])