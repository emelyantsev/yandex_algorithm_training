
s = input()

n = int(input())

words_to_ind = {}
ind_to_word = []

for i in range(n):

    word = input()

    words_to_ind[ word ] = i
    ind_to_word.append( word )


dp = []

for i in range(len(s)):

    found = False

    for w, ind in words_to_ind.items():

        if len(w) == i + 1  and s[0:i+1] == w :
            dp.append(ind)
            found = True
            break
        elif len(w) < i + 1 and dp[i - len(w)] != -1 and s[i - len(w) + 1:i+1] == w:
            dp.append(ind)
            found = True
            break

    if not found:
        dp.append(-1)
    

assert dp[-1] != -1

res_words = []

i = len(dp) - 1

while i >= 0:

    res_words.append( ind_to_word[dp[i]] )

    i -= len(res_words[-1])

res = " ".join(reversed(res_words))

print(res)

