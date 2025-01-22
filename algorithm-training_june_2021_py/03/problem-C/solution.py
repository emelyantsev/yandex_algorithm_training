

from collections import defaultdict


nums = list( map(int, input().split() )) 

counts = defaultdict(int)

for num in nums:

    counts[num] += 1

for num in nums:

    if (counts[num] == 1):
        print(num, end=' ')

print()