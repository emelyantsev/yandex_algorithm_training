from collections import Counter


line = list(map(int, input().split() ) ) 

n, k = line[0], line[1]

t = list(map(int, input().split() ) ) 

c = Counter(t)

#print(c)

res = []

while True:

    for key, val in c.items():

        if val != 0:
            res.append(key)
            c[key] -= 1

            if len(res) == k:
                break

    if len(res) == k:
        break

for r in res:
    print(r, end=' ')
print()
