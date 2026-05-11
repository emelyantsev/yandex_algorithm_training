from collections import deque


line = list(map(int, input().split()))

n, b = line[0], line[1]

a = list(map(int, input().split()))

res = 0

q = deque()

for i, ai in enumerate(a):

    q.append( (ai, i) )


for i in range(n):

    count = b

    while count > 0 and q and q[0][1] <= i:

        if count >= q[0][0]:

            res += ( i - q[0][1] + 1 ) * q[0][0]

            count -= q[0][0]
            q.popleft()        
            

        else:

            res += ( i - q[0][1] + 1 ) * count

            item = (q[0][0] - count, q[0][1])

            q.popleft()
            q.appendleft(item)
            count = 0

while len(q) > 0:

    res += ( n - q[0][1] + 1 ) * q[0][0]
    q.popleft()  


print(res)




