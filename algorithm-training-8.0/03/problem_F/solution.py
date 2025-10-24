import sys

from typing import List

class Solution:

    def __init__(self, n : int) -> None:
        self.n = n

    def build_tree(self, parents : List[int]) -> None:

        self.children = [ [] for i in range(self.n + 1)]
        self.root = -1

        for i in range(self.n):

            if parents[i] == 0:

                self.root = i+1

            self.children[ parents[i] ].append(i+1)

        self.time = [[-1, -1] for i in range(self.n + 1) ]

        self._process(self.root, 0)


    def _process(self, node : int, t : int ) -> int:

        self.time[node][0] = t

        curr_time = t

        for child in self.children[node]:
            curr_time = self._process(child, curr_time+1)

        self.time[node][1] = curr_time

        return curr_time

    def is_ansector(self, a : int, b : int) -> bool:

        at = self.time[a]
        bt = self.time[b]

        if bt[0] > at[0] and bt[1] <= at[1]:
            return True
        else:
            return False



if __name__ == '__main__':

    n = int(input())

    sys.setrecursionlimit(n+1)

    sln = Solution(n)

    parents = list(map(int, input().split() ) )

    sln.build_tree(parents)

    m = int(input())

    for i in range(m):
        a, b = map( int, input().split() )
        print(1 if sln.is_ansector(a, b) else 0)