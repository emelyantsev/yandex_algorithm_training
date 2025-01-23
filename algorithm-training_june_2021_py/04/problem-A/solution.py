from collections import defaultdict

n = int(input())

counts = defaultdict(int)

for i in range(n):

    p =  list( map(int, input().split() ) )

    d = p[0]
    a = p[1]

    counts[d] += a

for key in sorted(counts.keys() ):
    print(key, counts[key])