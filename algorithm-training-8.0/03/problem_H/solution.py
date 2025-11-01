from queue import Queue
from math import inf

if __name__ == '__main__':

    n = int(input())
    a = list(map(int, input().split()))

    G = [ [] for i in range(n) ]

    for i in range(n-1):

        line = list(map(int, input().split()))
        v, u = line[0]-1, line[1]-1

        G[v].append(u)
        G[u].append(v)

    total = sum(a)

    leafs = [ i for i in range(n) if len(G[i]) == 1  ]

    counts = [a[i] for i in range(n)]

    edges_counts = {}
    edges_sets = [ set(G[i]) for i in range(n) ]

    q = Queue()

    for leaf in leafs:

        q.put(leaf)

    while not q.empty():

        cur = q.get()

        assert len(edges_sets[cur] ) <= 1

        for vi in edges_sets[cur]:

            edges_sets[vi].remove(cur)
            counts[vi] += counts[cur]

            edges_counts[ (cur, vi) ] = counts[cur]
            edges_counts[ (vi, cur) ] = total - counts[cur]

            if len(edges_sets[vi]) == 1:
                q.put(vi)

    
    best_res = inf
    best_ind = -1

    for i in range(n):

        cur_res = max(  [ edges_counts[(vi, i)] for vi in G[i] ] + [a[i]] )

        if cur_res < best_res:
            best_res = cur_res
            best_ind = i

    print(best_ind+1)




