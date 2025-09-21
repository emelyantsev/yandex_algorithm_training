from math import inf
from typing import List

def find_closest_unvisited(d : List, visited : List) -> int :

    best_d = inf
    best_i = -1

    for i in range(len(d)):
        if not visited[i]  and d[i] != inf and d[i] < best_d:
            best_i = i
            best_d = d[i]
    
    return best_i




N = int(input())

line = list(map(int, input().split()))

d, v = line[0], line[1]

R = int(input())

buses = [list() for i in range(N+1)]

for i in range(R):

    line = list(map(int, input().split()))

    s, ts, f, tf = line[0], line[1], line[2], line[3]

    buses[s].append((f, ts, tf))


times = [inf for i in range(N+1)]
times[d] = 0

visited = [False for i in range(N+1)]



while ( curr := find_closest_unvisited(times, visited) ) != -1:

    visited[curr] = True

    for bus in buses[curr]:

        if times[curr] <= bus[1] and times[bus[0]] > bus[2]:
            times[bus[0]] = bus[2]

print(times[v] if  times[v] != inf else -1)

