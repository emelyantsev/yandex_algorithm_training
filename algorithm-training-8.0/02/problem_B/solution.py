

s = input()

l = 0
r = 1

for c in s:

    if c == 'L':

        l, r = min(l+1, r+1), r

    elif c == 'R':
        
        l, r = l, min(l+1, r+1)

    else:

        l += 1
        r += 1

print(r)
    
