n = int( input() )
points = []

#print(len(points))
#print(n)

for i in range(n):
    x, y = map(int, input().split())
    points.append((x,y))

ans = 0

for i in range(n):

    used_vectors = set()
    neig = []

    for j in range(n):

        if (i == j):
            continue

        vx = points[i][0] - points[j][0]
        vy = points[i][1] - points[j][1]

        assert (vx, vy) != (0, 0)

        vlen = vx**2 + vy**2
        neig.append(vlen)

        if (vx, vy) in used_vectors:
            ans -= 1

        used_vectors.add( (-vx,-vy) )

    neig.sort()

    r = 0
    for l in range(len(neig)):
        while r < len(neig) and neig[l] == neig[r]:
            r += 1
        ans += r - l - 1

print(ans)
        