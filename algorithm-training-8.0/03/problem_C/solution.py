from typing import List, Tuple


def isOk( words : List[Tuple[int, int]], w : int, h : int, k : float) -> bool:

    ch = 0.
    cw = 0.

    for i in range(len(words)):

        ai, bi = words[i][0] * k, words[i][1] * k

        if cw != 0:

            if words[i][1] == words[i-1][1]:

                if ai + cw <= w:
                    cw += ai
                    continue
            cw = 0

        if ai <= w and bi + ch <= h:
            cw += ai
            ch += bi
        else:
            return False
        
    return True



if __name__ == '__main__':

    line = list(map(int, input().split()))
    n, w, h = line[0], line[1], line[2]

    words = []

    for i in range(n):
        line = list(map(int, input().split()))
        words.append( (line[0], line[1]) )


    res = isOk(words, w, h, 1.41)


    sa = sum( [ word[0] for word in words]   )
    sb = sum( [ word[1] for word in words]   )

    min_a = min( [ word[0] for word in words]   )
    min_b = min( [ word[1] for word in words]   )


    eps = 0.00000001

    l = min( w / sa , h / sb) - eps
    r = min( w / min_a, h / min_b  ) + 1

    

    while r - l > eps:

        assert r > l

        #assert isOk(words, w, h, l) 
        #assert not isOk(words, w, h, r)

        mid = (l+r) / 2

        if isOk(words, w, h, mid):
            l = mid
        else:
            r = mid
    
    print(f'{l:0.12f}')



