from sys import exit


def count(d : int) -> int:

    assert d != 0
    
    if d == 1:
        return 0
    else:
        return (d-1) * 3



line = list(map(int, input().split() ) )

x, y = line[0], line[1]

line = list(map(int, input().split() ) )


f, g = line[0], line[1]

if x == f and y == g:
    print(0)
    exit(0)

dx, dy = abs(x-f), abs(y-g)

res = -1

if dx == 0:
    res = count(dy)
elif dy == 0:
    res = count(dx)
else:

    res = count(dx) + count(dy) + 1

print(res)


