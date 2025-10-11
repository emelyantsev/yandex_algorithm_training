N = int(input())

dp = [1]

for i in range(1, N+1):

    curr = 0

    if i-3 >= 0:
        curr += dp[i-3]
    if i-2 >= 0:
        curr += dp[i-2]
    
    curr += dp[i-1]

    dp.append(curr)

print(dp[-1])