from typing import List, Tuple


def lower_bound(nums : List[Tuple[int, int]], start : int, target : int ) -> int:
    
    low = start
    high = len(nums) - 1
    res = len(nums)

    while low <= high:
        mid = (high + low) // 2

        if nums[mid][0] >= target:
            res = mid
            high = mid - 1
        else:
            low = mid+1

    return res

def upper_bound(nums : List[Tuple[int, int]], start : int, target : int ) -> int:
    
    low = start
    high = len(nums) - 1
    res = len(nums)

    while low <= high:
        mid = (high + low) // 2

        if nums[mid][0] > target:
            res = mid
            high = mid - 1
        else:
            low = mid+1

    return res




if __name__ == '__main__':


    line = list( map(int, input().split() ) ) 

    n, p = line[0], line[1]

    line = list( map(int, input().split() ) ) 

    nums = []

    for i in range(n):

        nums.append( (line[i], i+1) )

    nums.sort()

    best_pair = nums[1][1], nums[0][1]
    best_val = abs ( nums[1][0] / nums[0][0] - p )

    for j in range(n-1):

        ci = nums[j][0] * p
        upper_ind = upper_bound(nums, j+1, ci)

        low_ind = upper_ind - 1

        curr_pair = None
        curr_val = None

        if low_ind != j:

            curr_pair = nums[low_ind][1], nums[j][1]
            curr_val = abs( nums[low_ind][0] / nums[j][0]  - p )

        if upper_ind != n:

            upper_pair = nums[upper_ind][1], nums[j][1]
            upper_val = abs( nums[upper_ind][0] / nums[j][0]  - p )

            if curr_val is None or upper_val < curr_val:

                curr_val = upper_val
                curr_pair = upper_pair

        assert curr_val is not None and curr_pair is not None

        if curr_val < best_val:
            best_val = curr_val
            best_pair= curr_pair


print(best_pair[0], best_pair[1])



