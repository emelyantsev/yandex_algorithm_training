# Main idea : use heap but not delete updated items, just add new ones and check visited


from typing import List, Set
from math import inf

import heapq

def find_closest_unvisited(h : List, visited : Set) -> int :

    while True:

        if len(h) == 0:
            return -1
        
        else:

            d, ind = heapq.heappop(h)

            if ind in visited:
                continue
            else:
                return ind


line = list(map(int, input().split() ) ) 

N, E = line[0], line[1]


g = [ dict() for i in range(N+1) ]
prev = [ -1 for i in range(N+1) ]


for i in range(E):

    line = list(map(int, input().split() ) ) 

    s, f, d = line[0], line[1], line[2]

    g[s][f] = d
    g[f][s] = d

line = list(map(int, input().split() ) ) 

S, F = line[0], line[1]


d = [ inf for i in range(N+1) ]
visited = set()

d[S] = 0

h = []
heapq.heappush(h, (0, S))


while ( curr := find_closest_unvisited(h, visited) ) != -1:

    visited.add(curr)

    for ind, edge_len in g[curr].items():

        di = d[curr] + edge_len

        if di < d[ind]:
            d[ind] = di
            prev[ind] = curr

            heapq.heappush(h, (di, ind) ) 


print(d[F] if  d[F] != inf else -1)


