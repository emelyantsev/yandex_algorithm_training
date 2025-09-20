from typing import List
from math import inf

def find_closest_unvisited(d : List, visited : List) -> int :

    best_d = inf
    best_i = -1

    for i in range(len(d)):
        if not visited[i]  and d[i] != inf and d[i] < best_d:
            best_i = i
            best_d = d[i]
    
    return best_i


line = list(map(int, input().split() ) ) 

N, S, F = line[0], line[1]-1, line[2]-1


mat = []


for i in range(N):

    line = list(map(int, input().split() ) ) 
    mat.append(line)


d = [ inf for i in range(N) ]
visited = [False for i in range(N)]
prev = [ -1 for i in range(N) ]

d[S] = 0


while ( curr := find_closest_unvisited(d, visited) ) != -1:

    visited[curr] = True

    for i in range(N):

        if curr != i and mat[curr][i] != -1:

            di = d[curr] + mat[curr][i]

            if di < d[i]:
                d[i] = di
                prev[i] = curr

print(d[F] if  d[F] != inf else -1)


