from collections import Counter

s = input()

c = Counter(s)

counts = [  count for count in c.values()  ]

assert sum(counts) == len(s)

res = 0

for i in range(len(counts)):

    for j in range(i+1, len(counts)):

        res += counts[i] * counts[j]

print(res + 1)
