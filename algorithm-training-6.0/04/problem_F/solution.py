
from typing import List, Tuple
import sys


class Tree:

    def __init__(self, n : int) -> None:
        
        self.workers_of : List[List[int]] = [ [] for i in range(n) ]
        self.n : int = n
        self.counts : List[int] = [0 for i in range(n) ]


    def add(self, boss : int , worker : int) -> None:

        self.workers_of[boss].append(worker)


    def calc_counts(self, ind : int) -> Tuple[int, int] :
        
        cnt, sum = 1, 1

        for child in self.workers_of[ind]:

            child_cnt, child_sum = self.calc_counts(child)

            cnt += child_cnt
            sum += child_sum + child_cnt


        self.counts[ind] = sum

        return cnt, sum
    
    def print_counts(self):

        for cnt in self.counts:
            print(cnt, end=' ')
        print()



if __name__ == '__main__':


    N = int(input())

    sys.setrecursionlimit( max(1000, N) )

    tree = Tree(N)

    a = list(map(int, input().split() ) )

    for i in range(N-1):

        tree.add( a[i]-1, i+1)

    tree.calc_counts(0)

    tree.print_counts()


        
        