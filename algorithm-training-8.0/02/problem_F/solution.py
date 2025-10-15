n = int(input())

t = []

for i in range(n):
    t.append(input())

dp = []
dpi = []

res = 0

for i in range(3):

    if t[0][i] == 'W':
        dpi.append(-1)
    elif t[0][i] == 'C':
        dpi.append(1)
    else:
        dpi.append(0)

res = max(res, max(dpi))
dp.append(dpi)


for i in range(1, n):

    dpi = [-1, -1, -1]

    if t[i][0] != 'W':

        if dp[-1][0] != -1 or dp[-1][1] != -1:
            dpi[0] = max(dp[-1][0], dp[-1][1]) + (1 if t[i][0] == 'C' else 0)

    
    if t[i][1] != 'W':

        if dp[-1][0] != -1 or dp[-1][1] != -1 or dp[-1][2] != -1:
            dpi[1] = max(dp[-1][0], dp[-1][1], dp[-1][2]) + (1 if t[i][1] == 'C' else 0)

    if t[i][2] != 'W':

        if dp[-1][1] != -1 or dp[-1][2] != -1:
            dpi[2] = max(dp[-1][1], dp[-1][2]) + (1 if t[i][2] == 'C' else 0)

    res = max(res, max(dpi))

    if dpi == [-1,-1,-1]:
        break
    else:
        dp.append(dpi)

print(res) 
        


