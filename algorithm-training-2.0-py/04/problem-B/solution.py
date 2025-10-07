from collections import defaultdict

counts = defaultdict(int)

while True:

    try:
        
        line = input().split()

        name = line[0]
        count = int(line[1])

        counts[name] += count

    except EOFError:
        break

for name in sorted(counts.keys()):
    print(name, counts[name])