

if __name__ == '__main__':

    x1 = int( input() )
    y1 = int( input() )
    x2 = int( input() )
    y2 = int( input() )
    x = int( input() )
    y = int( input() )
    

    assert x1 < x2 and y1 < y2

    assert not ( x >= x1 and x <= x2 and y >= y1 and y <= y2 )

    dx1 = abs(x-x1)
    dx2 = abs(x-x2)
    dy1 = abs(y-y1)
    dy2 = abs(y-y2)

    ans: str

    if y >= y2:

        if x <= x1:
            ans = 'NW'
        elif x >= x2:
            ans = 'NE'
        else:
            ans = 'N'

    elif y <= y1:

        if x <= x1:
            ans = 'SW'
        elif x >= x2:
            ans = 'SE'
        else:
            ans = 'S'

    elif x <= x1:

        ans = 'W'

    elif x >= x2:

        ans = 'E'
    else:

        assert False

    print(ans)

        

    