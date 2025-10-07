
nums = list( map(int, input().split() ) )

prev_nums = set()

for num in nums:

    if (num in prev_nums):
        print("YES")
    else:
        print("NO")
    
    prev_nums.add(num)