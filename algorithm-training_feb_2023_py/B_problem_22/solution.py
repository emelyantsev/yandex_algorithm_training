
line = list(map(int, input().split() ) ) 

N = line[0]
K = line[1]

ans = []
ans.append(1)

for i in range(N-1):

    l = len(ans)
    res = 0

    for j in range(K):

        ind = l - j - 1
        
        if ind < 0:
            break
        
        res += ans[ind]

    ans.append(res)

print(ans[-1])