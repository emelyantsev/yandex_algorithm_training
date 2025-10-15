
class Solution:

    def __init__(self):
        pass

    def count(self, n : int) -> int:

        self.dp = [ [-1 for j in range(n+1)] for i in range(n+1)  ]

        for i in range(n+1):
            self.dp[0][i] = 1

        res = 0
        for i in range(1, n+1):
            res += self.get_dp(n-i, i-1)

        return res
    
    def get_dp(self, total : int, max_len : int ) -> int:

        if self.dp[total][max_len] != -1:
            return self.dp[total][max_len]

        min_pos = ( max_len + 1 ) * max_len / 2

        if min_pos < total :
            self.dp[total][max_len] = 0
            return 0
        
        if min_pos == total:
            self.dp[total][max_len] = 1
            return 1

        res = 0

        for i in range(1, min( max_len+1, total+1   )):
            res += self.get_dp( total - i, i  - 1  )

        self.dp[total][max_len] = res

        return res


n = int(input())

res = Solution().count(n)

print(res)



