from typing import List


class Solution:

    def __init__(self, t : List[List[int]]) -> None:
        
        self.t = t
        self.n = len(t)
        self.m = len(t[0])
        self.dp = [ [-1 for j in range(m)] for i in range(n) ]

    def _is_valid(self, i : int, j : int) -> bool:

        if i < 0 or i >= self.n or j < 0 or j >= self.m:
            return False
        else:
            return True

    def _get_dp(self, i : int , j : int) -> int:

        if self.dp[i][j] != -1:
            return self.dp[i][j]
        
        vals = [ self._get_dp( i+di, j+dj )  for di, dj in [ (0,1), (1,0), (-1, 0), (0, -1) ]  if ( self._is_valid(i+di,j+dj) and t[i+di][j+dj] == t[i][j] + 1) ]
        ans = 1 + ( max( vals ) if len(vals) > 0 else 0 )  
        self.dp[i][j] = ans

        return ans
    
    def get_max_length(self):

        best_len = 0
        cells = []

        for i in range(self.n):
            for j in range(self.m):

                cells.append( ( -self.t[i][j], i, j ) )

        cells.sort()

        for c in cells:

            curr = self._get_dp(c[1], c[2])
            best_len = max(best_len, curr)

        return best_len

if __name__ == '__main__':


    line = list( map( int, input().split() ) )
    n, m = line[0], line[1]


    t = []

    for i in range(n):
        line = list( map( int, input().split() ) )
        t.append( line )

    
    solution = Solution(t)

    ans = solution.get_max_length()

    print(ans)






