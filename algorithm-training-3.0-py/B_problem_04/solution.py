

def getSeatNumber(r : int, q : int) -> int:

    return (r-1)*2 + q - 1

def getRowAndSeat( n : int) -> tuple[int, int]:
    q = n % 2 + 1
    r = n // 2 + 1
    return (r,q)



# n = getSeatNumber(2, 1)
# r, q = getRowAndSeat(n)

# for i in range(100):
#     r, q = getRowAndSeat(i)

#     assert getSeatNumber(r, q) == i
# exit(0)
# pass

N = int(input())
K = int(input())

r = int(input())
q = int(input())

p = getSeatNumber(r, q)

r1 = None
q1 = None
r2 = None
q2 = None

if p + K < N:
    r1, q1 = getRowAndSeat(p + K)

if p - K >= 0:
    r2, q2 = getRowAndSeat(p - K)


if r1 is None and r2 is not None:
    print(r2, q2)
elif r1 is not None and r2 is None:
    print(r1, q1)
elif r1 is None and r2 is None:
    print(-1)
else:

    d1 = r1 - r
    d2 = r - r2
    if d1 <= d2:
        print(r1, q1)
    else:
        print(r2, q2)