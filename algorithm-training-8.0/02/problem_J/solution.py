
from typing import List, Tuple, Optional
from math import inf
from sys import exit

def getCost(cnt: int, shop_params : List[int] ) -> Optional[ Tuple[int, int] ]:

    p, r, q, f = shop_params[0], shop_params[1], shop_params[2], shop_params[3]

    if cnt > f:
        return None
    
    price = p if cnt < r else q

    total = price * cnt

    if r > cnt and q * r < total  and r <= f:
        return q*r, r 
    else: 
        return total, cnt


if __name__ == '__main__':


    line = list( map( int, input().split() ) )
    N, L = line[0], line[1]

    shop_params = []

    for i in range(N):
        
        params = list( map( int, input().split() ) )
        shop_params.append( params )

    dp = [ [  (0, 0) if j == 0 else None  for j in range(L+1) ] for i in range(N+1) ]


    for i in range(1, N+1):

        for j in range(1, L+1):

            best_var = inf
            best_cnt = 0

            if j == 11:
                stop = True

            for k in range(0, j+1):

                need = j - k
                curr_cost = getCost(need, shop_params[i-1] )

                if dp[i-1][k] is None or curr_cost is None:
                    continue
                else:
                    var = dp[i-1][k][0] + curr_cost[0]

                    if var < best_var:
                        best_var = var
                        best_cnt = curr_cost[1]

            
            if best_var == inf:
                break

            else:
                dp[i][j] = best_var, best_cnt



    if dp[-1][-1] is None:
        print(-1)
        exit(0)


    i, j = N, L

    ans = []

    while i > 0 or j > 0:

        assert dp[i][j] is not None
        ans.append( dp[i][j][1] )
        j -= min( dp[i][j][1], j)
        i -= 1

    print(dp[-1][-1][0])

    for c in reversed(ans):
        print(c, end=' ')
    print()