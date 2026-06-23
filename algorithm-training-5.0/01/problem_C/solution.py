

def count_keys(n : int) -> int:

    if n == 0:
        return 0
    else:

        res = 0

        res += n // 4

        if n % 4 == 3:
            res += 2
        elif n % 4 == 2:
            res += 2
        elif n % 4 == 1:
            res += 1
    
        return res

n = int(input())

total = 0

for i in range(n):

    num = int(input())

    total += count_keys(num)


print(total)