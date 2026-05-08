n = int(input())

a = list(map(int, input().split()))


line = list(map(int, input().split()))
m, k = line[0], line[1]

ans = [i for i in range(n)]

l = 0
r = 0
c = 0

while True:

    if r == n-1:
        break

    r += 1

    if a[r] == a[r-1]:

        c+=1 

        while c > k:

            l += 1

            if a[l] == a[l-1]:
                c -= 1

    elif a[r] < a[r-1]:

        l = r
        c = 0
    
    else:
        pass

    ans[r] = l


q = list(map(int, input().split()))

for qi in q:

    print(ans[qi-1] + 1, end= ' ')

print()



    
