

l = list(map(int, input().split()))

assert len(l) == 6

a, b, c, v0, v1, v2 = l[0], l[1], l[2], l[3], l[4], l[5]

a, b, c = min(a, b + c), min(b, a + c), min(c, a + b) 

var1 = a / v0 + c / v1 + b / v2
var2 = b / v0 + c / v1 + a / v2
var3 = a / v0 + a / v1 + b / v0 + b / v1

res = min(var1, var2, var3)

print(f"{res:.15f}")