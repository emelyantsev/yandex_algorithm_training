
if __name__ == '__main__':

    line = list(map(int, input().split()))

    N, R = line[0], line[1]

    d = list(map(int, input().split()))


    l = 0
    r = 1

    ans = 0

    while True:

        while r < N and d[r] - d[l] <= R:

            r += 1

        if r == N:
            break
        else:
            ans += N - r 

        l += 1

        
    print(ans)



