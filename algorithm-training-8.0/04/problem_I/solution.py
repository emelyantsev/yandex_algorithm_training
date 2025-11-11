

line = list(map(int, input().split() ) )

n, d = line[0], line[1]

i = 0

squares = {}

while i*i <= d:
    squares[i*i] = i
    i += 1

pos_pairs = []

i = 0

while (i2 := i * i) <= d:

    if d - i2 in squares:
        pos_pairs.append( (i, squares[d-i2] ) )
    
    i += 1


points = []
points_set = set()

for i in range(n):

    line = list(map(int, input().split() ) )
    point = (line[0], line[1] )
    points.append( point )
    points_set.add( point )

points.sort()

count = 0


for p in points:

    for dx, dy in pos_pairs:

        if dx == 0:

            p2 = p[0], p[1] + dy

            if p2 in points_set:
                count += 1
        
        else:

            if dy != 0:

                p21 = p[0]-dx, p[1] + dy

                if p21 in points_set:
                    count += 1

            p22 = p[0]+dx, p[1] + dy

            if p22 in points_set:
                count += 1

print(count)