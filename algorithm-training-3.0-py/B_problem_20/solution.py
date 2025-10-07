import heapq

N = int(input())

vals = list(map(int, input().split() ) )

heapq.heapify(vals)


while len(vals) != 0:
    
    print(vals[0])
    heapq.heappop(vals)