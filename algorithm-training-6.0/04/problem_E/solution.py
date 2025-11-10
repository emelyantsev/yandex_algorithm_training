
from typing import List
import sys

class Tree:

    def __init__(self, n : int) -> None:

        self.n : int = n
        self.G : List[List[int]] =  [ [] for i in range(n) ]

    def add_edge(self, v1 : int, v2 : int) -> None:

        self.G[v1].append(v2)
        self.G[v2].append(v1)

    def calc_counts(self) -> None:

        self.counts : List[int] = [ -1 for i in range(self.n) ]
        self.get_count(0)

        for c in self.counts:
            print(c, end=' ')
        print()

    def get_count(self, v : int) -> int:

        self.counts[v] = 1

        for vi in self.G[v]:

            if self.counts[vi] == -1:
                cnt = self.get_count(vi)
                self.counts[v] += cnt

        return self.counts[v]
    

        


if __name__ == '__main__':

    v = int(input())

    sys.setrecursionlimit(max(1000, v))

    tree = Tree(v)

    for i in range(v-1):
        line = list(map(int, input().split()))
        tree.add_edge(line[0]-1, line[1]-1)

    tree.calc_counts()


