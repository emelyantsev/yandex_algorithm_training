from math import inf
from queue import Queue
from typing import List, Dict


def find_closest_unvisited(t : List, visited : List) -> int :

    best_d = inf
    best_i = -1

    for i in range(1, len(t)):
        if not visited[i]  and t[i] != inf and t[i] < best_d:
            best_i = i
            best_d = t[i]
    
    return best_i


def bfs(start : int, g : Dict, t : List, v : List, time : List, parent : List) -> None:

    q = Queue()

    q.put(start)
    marked = set()
    marked.add(start)

    dist = [inf for _ in range(len(v))]
    dist[start] = 0

    while not q.empty():

        curr = q.get()

        for vi, di in g[curr].items():

            if vi in marked:
                continue

            dist[vi] = dist[curr] + di
            marked.add(vi)

            q.put(vi)


    for vi in range(1, len(v) ):

        ti = time[start] + t[vi] + dist[vi] / v[vi]

        if ti < time[vi]:
            time[vi] = ti
            parent[vi] = start
         


N = int(input())

t = [-1.0]
v = [-1.0]

for i in range(N):

    line = list(map(float, input().split() ) ) 
    t.append(line[0])
    v.append(line[1])

g = dict()

for i in range(N-1):

    line = list(map(int, input().split() ) ) 

    A, B, S = line[0], line[1], float(line[2])

    if A not in g:
        g[A] = dict()
        g[A][B] = S
    else:
        g[A][B] = S

    if B not in g:
        g[B] = dict()
        g[B][A] = S
    else:
        g[B][A] = S




time = [inf for _ in range(N+1)]
time[0] = 0
time[1] = 0

visited = [False for _ in range(N+1)]

parent = [-1 for _ in range(N+1)]

while ( curr := find_closest_unvisited(time, visited) ) != -1:

    visited[curr] = True

    bfs(curr, g, t, v, time, parent)



max_time = max( time )

print( f"{max_time:0.10f}")

idx_max = time.index(max_time)

res = []
res.append(idx_max)

p = parent[idx_max]

while p != -1:
    res.append(p)
    p = parent[p]

for pi in res:
    print(pi, end=' ')
print()


