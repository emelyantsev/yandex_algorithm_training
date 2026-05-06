

if __name__ == '__main__':

    line = list(map(int, input().split()))
    N, K = line[0], line[1]

    numbers = list(map(int, input().split()))

    ans = 0
    part_sums = {0}

    curr_sum = 0


    for i in range(N):

        curr_sum += numbers[i]

        needed = curr_sum - K

        if needed in part_sums:
            ans += 1

        part_sums.add(curr_sum)

    print(ans)


