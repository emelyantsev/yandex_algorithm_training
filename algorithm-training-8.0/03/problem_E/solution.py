from queue import Queue
import sys

if __name__ == '__main__':

    n = int(input())

    pred = [-1 for i in range(n)]
    child_count = [0 for i in range(n)]

    leafs = set([i for i in range(n)])

    for i in range(1, n):
        
        pred[i] = int(input())
        child_count[ pred[i] ] += 1

        if pred[i] in leafs:
            leafs.remove(pred[i])

    a = list(  map( int, input().split() ) )

    counts = {}

    q = Queue()

    for leaf in leafs:

        counts[leaf] = [0,0]
        q.put(leaf)

    while True:

        curr = q.get()

        if curr == 0:

            ans = abs( a[curr] - counts[curr][0] + counts[curr][1] ) + sum( counts[curr] )

            print(ans)
            sys.exit(0)

        
        par = pred[curr]

        if par not in counts:
            
            counts[par] = [0,0]

        counts[par][0] += counts[curr][0]
        counts[par][1] += counts[curr][1]

        diff_curr = a[curr] - counts[curr][0] + counts[curr][1] 

        if diff_curr > 0:
            counts[par][0] += diff_curr
        else:
            counts[par][1] += -diff_curr

        child_count[par] -= 1

        if child_count[par] == 0:
            q.put(par)




    

