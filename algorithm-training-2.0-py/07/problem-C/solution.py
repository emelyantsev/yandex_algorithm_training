# RE on Python 3.12.3 OK on Python 3.9 (PyPy 7.3.16)

M = int( input() )

segments = []

while True:

    line = list( map( int, input().split() ) )

    if line == [0, 0]:
        break
    
    segments.append( ( line[0], line[1] ) )

segments.sort()

curr = 0
i = 0

ans = []

while True:

    best = None

    while i < len(segments) and  segments[i][0] <= curr:

        if segments[i][1] >= curr:

            if best is None:
                best = segments[i]
            elif segments[i][1] > best[1]:
                best = segments[i]
        i += 1

    if best is None:
        print("No solution")
        exit(0)
    else:
        ans.append(best)
    
    curr = best[1]

    if best[1] >= M:
        break


print( len(ans) )

for seg in ans:
    print(seg[0], seg[1])

                


