from queue import Queue

n = int( input() )

edges = [ [] for i in range(n) ]

for i in range(n-1):

    line = list(map(int, input().split()))
    a, b = line[0]-1, line[1]-1

    edges[a].append(b)
    edges[b].append(a)


dist = {}

q = Queue()

for i in range(n):

    assert len(edges[i]) > 0

    if len(edges[i]) == 1:

        q.put(i)
        dist[i] = 0, -1

ans = -1

while ans == -1:

    v = q.get()

    for vi in edges[v]:

        if vi != dist[v][1] and vi in dist:
            ans = dist[vi][0] + dist[v][0] + 1
            break
        elif vi != dist[v][1] and vi not in dist:
            q.put(vi)
            dist[vi] = dist[v][0] + 1, v
        
    
print(ans)


        



    