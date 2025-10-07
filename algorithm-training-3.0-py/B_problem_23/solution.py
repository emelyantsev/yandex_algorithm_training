N = int(input())


ans = [ (0, -1) ]

for i in range(2, N+1):

    vars = []
    vars.append( ( ans[i-1-1][0], i-1 ) )
 
    if i % 2 == 0:

        vars.append( ( ans[i // 2 - 1][0], i // 2 ) )

    if i % 3 == 0:

        vars.append( ( ans[i // 3 - 1][0], i // 3 )  )

    best_var = min(vars)

    ans.append( (best_var[0]+1, best_var[1]  ))

#print(ans)

res = [N]

curr = ans[-1][1]

while curr != -1:

    res.append(curr)
    curr = ans[curr-1][1]


res.reverse()

print(len(res)-1)

for elem in res:
    print(elem, end=' ')
print();


