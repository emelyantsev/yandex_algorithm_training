score1 = input().strip().split(":")
score2 = input().strip().split(":")

who = int(input().strip())

g1_1, g1_2 = int(score1[0]), int(score1[1])
g2_1, g2_2 = int(score2[0]), int(score2[1])

assert g1_1 >= 0 and g1_1 <= 5 and g1_2 >= 0 and g1_2 <= 5
assert g2_1 >= 0 and g2_1 <= 5 and g2_2 >= 0 and g2_2 <= 5

assert who == 1 or who == 2

if who == 1:

    sum1 = g1_1 + g2_1
    sum2 = g1_2 + g2_2

    if sum1 > sum2:
        print(0)
    elif sum1 == sum2:

        if g2_1 > g1_2:
            print(0)
        else:
            print(1)
        
    else:

        needed = sum2 - sum1

        if g2_1 + needed > g1_2:
            print(needed)
        else:
            print(needed+1)

else:
    sum1 = g1_1 + g2_1
    sum2 = g1_2 + g2_2

    if sum1 > sum2:
        print(0)
    elif sum1 == sum2:

        if g1_1 > g2_2:
            print(0)
        else:
            print(1)
        
    else:

        needed = sum2 - sum1

        if g1_1 > g2_2:
            print(needed)
        else:
            print(needed+1)

