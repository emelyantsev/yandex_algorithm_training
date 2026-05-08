

line = list(map(int, input().split()))

n, c = line[0], line[1]

s = input()


best_len = 1

l = 0
r = 0

ac = 1 if s[0] == 'a' else 0
bc = 1 if s[0] == 'b' else 0

score = 0


while l < n:

    if r < n-1:

        if s[r+1] == 'a':
            ac += 1
            r += 1

            best_len = max(r-l+1, best_len)

        elif s[r+1] == 'b':

            new_score = score + ac

            if new_score <= c:

                score = new_score
                r += 1
                bc += 1
                best_len = max(r-l+1, best_len)

            else:

                if s[l] == 'a':
                    score -= bc
                    ac -= 1

                elif s[l] == 'b':
                    bc -= 1

                l += 1
        else:
            r += 1
            best_len = max(r-l+1, best_len)


    else:

        if s[l] == 'a':
            score -= bc
            ac -= 1

        elif s[l] == 'b':
            bc -= 1

        l += 1

        best_len = max(r-l+1, best_len)

        
print(best_len)


