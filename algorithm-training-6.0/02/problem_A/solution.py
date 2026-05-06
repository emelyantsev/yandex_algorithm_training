if __name__ == '__main__':


    n = int(input())

    a = list(map(int, input().split()))

    b = [a[0]]

    for i in range(1, n):
        b.append(b[-1] + a[i])

    
    for bi in b:
        print(bi, end=' ')
    print()