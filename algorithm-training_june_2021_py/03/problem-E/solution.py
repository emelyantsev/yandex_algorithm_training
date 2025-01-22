
from collections import defaultdict

M = int(input() )

tests = []

for i in range(M):

    test = set(  input() ) 
    tests.append(test)

N = int(input())

nums = []

best_count = 0


nums_counts = defaultdict(int)

for i in range(N):

    num = input()
    nums.append(num)

    num_set = set(num)

    count = 0

    for test in tests:

        if ( num_set.intersection( test ) == test ):
            count += 1

    best_count = max(count, best_count)

    nums_counts[num] = count

for num in nums:

    if (nums_counts[num] == best_count):
        print(num)


