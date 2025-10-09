
from typing import List
from sys import exit

def isGood(t : List[str], i : int, j : int) -> bool:

    if i == 0 and j == 5:
        stop = True

    
    n, m = len(t), len(t[0])

    if t[i][j] == '.':
        return False
    
    c = t[i][j]

    cnt = 0

    for k in range(1, 5):

        if i + k == n or t[i+k][j] != c:
            break
        else:
            cnt += 1

    if cnt == 4:
        return True
            
    
    cnt = 0

    for k in range(1, 5):

        if j + k == m or t[i][j+k] != c:
            break
        else:
            cnt += 1

    if cnt == 4:
        return True

    cnt = 0

    for k in range(1, 5):

        if i+k == n or j + k == m or t[i+k][j+k] != c:
            break
        else:
            cnt += 1

    if cnt == 4:
        return True

    cnt = 0

    for k in range(1, 5):

        if i+k == n or j - k == -1 or t[i+k][j-k] != c:
            break
        else:
            cnt += 1

    if cnt == 4:
        return True

    return False



line = list(map(int, input().split()))

n, m = line[0], line[1]

t = []

for i in range(n):

    t.append(input())


for i in range(n):
    for j in range(m):

        if isGood(t, i, j):
            print("Yes")
            exit(0)

print("No")
            