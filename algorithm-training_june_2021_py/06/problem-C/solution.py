

def get_value(a : float, b : float, c : float, d : float, x : float) -> float :

    return a * x**3 + b * x**2 + c * x + d



line = list( map(int, input().split() ) )

a = line[0]
b = line[1]
c = line[2]
d = line[3]


left = -1000000.
right = 1000000.

val_left = get_value(a, b, c, d, left)
val_right = get_value(a, b, c, d, right)

while True:

    mid = (right + left) / 2

    val_mid = get_value(a, b, c, d, mid)

    if val_mid == 0 or abs(right - left) < 0.00000001:
        print("{:.10f}".format(mid))
        break

    assert val_left > 0 and val_right < 0 or val_left < 0 and val_right > 0

    if val_mid > 0 and val_left > 0 or val_mid < 0 and val_left < 0:
        left = mid
        val_left = val_mid
    elif val_mid > 0 and val_right > 0 or val_mid < 0 and val_right < 0:
        right = mid
        val_right = val_mid
    
    


