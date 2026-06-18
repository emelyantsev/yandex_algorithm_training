"""
    Solution is wrong, but some code is helpful, 
    TODO: write correct solution
"""


from typing import List, Tuple
import sys

MOD = 1000000007


class BinomCounter:

    def __init__(self, N : int) -> None:

        self.data = [ [-1 for j in range(N+1)] for i in range(N+1)  ]
        self.N = N

    def getCoef(self, n : int, k : int) -> int:

        assert n >= 0 and n <= self.N
        assert k >= 0 and k <= n

        if k == n or k == 0:
            return 1
        
        else:

            if self.data[n][k] != -1:
                return self.data[n][k]
            else:
                self.data[n][k] = ( self.getCoef(n-1, k-1) + self.getCoef(n-1, k) ) % MOD
                return self.data[n][k]
        
        assert False


class Tree:

    def __init__(self, n : int) -> None:
        
        self.graph : List[List[int]] = [ [] for _ in range(n) ]
        self.n : int = n
        self.binom_counter = BinomCounter(n)
        self.is_child : List[bool] = [False for _ in range(n)]


    def add(self, v1 : int , v2 : int) -> None:

        self.graph[v1].append(v2)
        self.is_child[v2] = True

    def get_root(self) -> int:

        assert self.is_child.count(False) == 1

    
        for i in range(self.n):

            if self.is_child[i] == False:
                return i
            
        
        assert False


    def get_count(self, v : int) -> Tuple[int, int] :


        child_permut_cnt = []
        child_cnt = []

        for child in self.graph[v]:
            
            p_cnt, cnt = self.get_count(child)
            child_permut_cnt.append(p_cnt)
            child_cnt.append(cnt) 

        child_sum = sum(child_cnt)

        res_cnt = child_sum + 1
        res_permute_cnt = 1

        for val in child_permut_cnt:
            res_permute_cnt = (res_permute_cnt * val) % MOD

        perm_cnt = 1

        for cnt in child_cnt:

            perm_cnt = ( perm_cnt * self.binom_counter.getCoef(child_sum, cnt)  ) % MOD 
            child_sum -= cnt

        res_permute_cnt = (res_permute_cnt * perm_cnt) % MOD

        return res_permute_cnt, res_cnt
            

if __name__ == '__main__':


    N = int(input())

    sys.setrecursionlimit(max(1000, N+1))

    tree = Tree(N)

    for i in range(N-1):

        line = list(map(int, input().split()))
        a, b = line[0] - 1, line[1] - 1

        tree.add(a, b)

    
    res, child_cnt = tree.get_count( tree.get_root()  )

    print(res)