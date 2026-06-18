
def instersects(a1 : int, b1 : int, a2, b2) -> bool:

    if a1 >= a2 and a1 <= b2:
        return True
    elif b1 >= a2 and b1 <= b2:
        return True
    elif a2 >= a1 and a2 <= b1:
        return True
    elif b2 >= a1 and b2 <= b1:
        return True
    else:
        return False


line = list(map(int, input().split()))

P, V = line[0], line[1]

line = list(map(int, input().split()))

Q, M = line[0], line[1]


a1, b1 = P-V, P+V
a2, b2 = Q-M, Q+M

if instersects(a1, b1, a2, b2):
    
    a = min(a1, a2)
    b = max(b1, b2)
    print(b - a + 1)
else:
    print(b1 - a1 + 1 + b2 - a2 + 1)