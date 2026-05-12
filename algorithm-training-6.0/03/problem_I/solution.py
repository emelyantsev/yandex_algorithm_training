from collections import deque

N = int(input())

line = list(map(int, input().split()))

a, b = line[0]-1, line[1]-1


queues = [deque() for _ in range(4) ]

for i in range(N):

    line = list(map(int, input().split()))

    di, ti = line[0], line[1]

    queues[di-1].append( (i, ti ) )

for j in range(4):
    queues[j] = deque(sorted(queues[j], key=lambda car: car[1]))


result = [-1 for _ in range(N) ]

i = 0

while any(queues):

    i += 1

    cars = [ q[0] if len(q) > 0 and q[0][1] <= i else None for q in queues ]


    for j, car in enumerate(cars):

        if car is None:
            continue
    
        lj = (j+1) % 4
        rj = (j-1) % 4

        if j == a or j == b:

            if ( rj == a or rj == b ) and cars[rj] != None:
                continue
            else:
                result[car[0]] = i
                queues[j].popleft()

        else:

            if cars[a] != None or cars[b] != None:
                continue

            if cars[rj] != None:
                continue
            
            result[car[0]] = i
            queues[j].popleft()

for ri in result:

    print(ri)





