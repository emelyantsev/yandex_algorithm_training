from math import inf

line = list(map(int, input().split()))

n, m = line[0], line[1]

t = []

for i in range(n):

    t.append(input())

cn = [0 for _ in range(n)]
cm = [0 for _ in range(m)]


for i in range(n):
    for j in range(m):

        if t[i][j] == '+':
            cn[i] += 1 
            cm[j] += 1
        elif t[i][j] == '-':
            cn[i] -= 1 
            cm[j] -= 1
        elif t[i][j] == '?':
            cn[i] += 1 
            cm[j] -= 1

best_res = -inf


for i in range(n):
    for j in range(m):

        if t[i][j] == '?':

            res = cn[i] - 2 - cm[j]
        
        else:

            res = cn[i] - cm[j]

        best_res = max(res, best_res)


print(best_res)