from collections import defaultdict


class reversor:
    def __init__(self, obj):
        self.obj = obj

    def __eq__(self, other):
        return other.obj == self.obj

    def __lt__(self, other):
        return other.obj < self.obj

counts = defaultdict(int)

while True:

    try:
        
        line = input().split()

        for word in line:

            counts[word] += 1


    except EOFError:
        
        break

items = []

for word, count in counts.items():

    items.append( (count, word))

items.sort( key=lambda y: ( y[0], reversor(y[1]) ), reverse=True )

for item in items:
    print( item[1])