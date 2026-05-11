N = int(input())

a = list(map(int, input().split()))

ans = [-1 for _ in range(N)]

cur_nums = []

for i in range(N):

    while len(cur_nums) > 0 and a[cur_nums[-1]] > a[i]:

        ans[cur_nums[-1]] = i
        cur_nums.pop()

    cur_nums.append(i)

for ai in ans:

    print(ai, end=' ')

print()