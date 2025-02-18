
line = list(map(int, input().split() ) )

N = line[0]
M = line[1]

t = []

for i in range(N):

    t.append( list( map(int, input().split() ) )  )

dp = [ [-1 for j in range(M) ] for i in range(N) ]

for i in range(N):
    for j in range(M):

        if i == 0 and j == 0:
            dp[i][j] = t[i][j]
        elif i == 0 and j != 0:
            dp[i][j] = t[i][j] + dp[i][j-1]
        elif i != 0 and j == 0:
            dp[i][j] = t[i][j] + dp[i-1][j]
        else:
            dp[i][j] = t[i][j] + min( dp[i-1][j], dp[i][j-1] )

print(dp[-1][-1])
