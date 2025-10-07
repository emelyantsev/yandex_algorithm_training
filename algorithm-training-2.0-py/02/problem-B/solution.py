
import sys

input_file = open('input.txt')
sys.stdin = input_file

#############################################


import math


nums = list( map(int, input().split() ) ) 

max_len = -math.inf

l = -1
r = -1


for i in range(len(nums)):

  if nums[i] == 2:
    l = i
  elif nums[i] == 1:

    r = max(r, i+1)

    while (r < len(nums) and nums[r] != 2):
        r += 1
    
    left = i - l if l != -1 else math.inf
    right = r - i if r != len(nums) else math.inf

    max_len = max( min(left, right), max_len )

print(max_len)


################################################

if input_file: input_file.close()