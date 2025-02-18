N = int(input())

nums = list(map(int, input().split()))

nums.sort()


dp = []

dp.append(nums[1]-nums[0])

for i in range(2, N):

    if i == 2:
        dp.append(nums[i]-nums[i-1] + dp[-1])
    
    else:

        dp.append(  min( nums[i]-nums[i-1] + dp[-1] ,  nums[i]-nums[i-1] + dp[-2] )    )

print(dp[-1])