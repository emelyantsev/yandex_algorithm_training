
import sys

input_file = open('input.txt')
sys.stdin = input_file

#############################################

l = list( map( int, input().split() ) )

L = l[0]
K = l[1]

legs = list( map( int, input().split() ) )

if (L % 2 == 1 ):

    mid = L // 2

    if (mid in legs):
        print(mid)

    else:

        i = 1
        j = K - 2

        ai = legs[0]
        aj = legs[K - 1]

        while (i < K and legs[i] < mid ):
            ai = legs[i]
            i += 1

        while (j >= 0 and legs[j] > mid):
            aj = legs[j]
            j -= 1

        print( ai, aj)

else:

    lm = L // 2 - 1
    rm = L // 2

    ai = legs[0]
    aj = legs[K - 1]

    i = 1
    j = K - 2

    while (i < K and legs[i] <= lm ):
        ai = legs[i]
        i += 1

    while (j >= 0 and legs[j] >= rm):
        aj = legs[j]
        j -= 1

    print( ai, aj)


################################################

if input_file: input_file.close()