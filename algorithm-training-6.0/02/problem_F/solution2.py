
if __name__ == '__main__':


    n = int(input())

    a = list(map(int, input().split()))

    ans = 0
    MOD = 1000000007

    ak = [a[-1]]

    for i in range(1, n):

        ak.append(  ( ak[-1] + a[n-i-1] ) % MOD )

    
    ak.reverse()

    aj = [ 0 ]

    for i in range(1, n):

        aj.append( ( aj[-1] + a[n-i-1] * ak[n-i] ) % MOD )


    aj.reverse()


    ai = [0, 0]

    for i in range(2, n):

        ai.append( ( ai[-1] + a[n-i-1] * aj[n-i]  ) % MOD  )

    ai.reverse()

    print(ai[0])
        

    
