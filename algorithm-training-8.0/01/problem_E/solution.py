
line = list( map(int, input().split() ) )


n, k = line[0], line[1]

while k != 0:

    q = n % 10
    
    if ( q == 2 or q == 4)  and k >= 4:

        c = k // 4

        n += 20 * c
        k = k % 4

    elif q == 0:
        break

    else:
        n += q
        k -= 1

print(n)

            
