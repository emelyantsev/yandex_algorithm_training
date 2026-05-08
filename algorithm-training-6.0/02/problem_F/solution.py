
if __name__ == '__main__':


    n = int(input())

    a = list(map(int, input().split()))

    ans = 0
    MOD = 1000000007

    for i in range(n-2):

        for j in range(i+1, n-1):

            for k in range(j+1, n):

                ans = (ans + a[i]*a[j]*a[k] ) % MOD

    print(ans)
