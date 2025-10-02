n = int(input())

l = list(map(int, input().split()))

a = [l[i] for i in range(0, len(l), 2)]
b = [l[i] for i in range(1, len(l), 2)]

min_a = min(a)
max_b = max(b)

if min_a < max_b:

    res = sum(a) - min_a + max_b - sum(b) - min_a + max_b 
else:
    res = sum(a) - sum(b)

print(res)