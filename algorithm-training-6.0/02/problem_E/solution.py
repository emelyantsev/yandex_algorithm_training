
if __name__ == '__main__':

    n = int(input())

    a = list(map(int , input().split() )) 

    a.sort()

    ans = []

    if n % 2 == 1:

        m = n // 2

        ans.append(a[m])
        l = m
        r = m
    
    else:

        m = (n-1) // 2

        ans.append(a[m])
        l = m
        r = m

    while True:

        lc = l
        rc =  n - r - 1

        if lc == 0 and rc == 0:
            break

        elif lc == rc:

            ans.append(a[l-1])
            l -= 1

        else:

            assert lc + 1 == rc 

            ans.append( a[r+1] )
            r += 1

    
    for ai in ans:
        print(ai, end=' ')
    
    print()


