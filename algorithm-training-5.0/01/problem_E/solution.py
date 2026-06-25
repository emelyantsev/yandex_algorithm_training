line = list(map(int, input().split()))

n, k, d = line[0], line[1], line[2]



n = n * 10
found = False

for i in range(9):

    if ( n + i ) % k == 0:
        
        found = True
        n += i
        break 

if found:

    ans = str(n) + "0" * (d-1)

    print(ans)

else:

    print(-1)