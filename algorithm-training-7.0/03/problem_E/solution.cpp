#include <iostream>
#include <cassert>

bool isPow2(long long num) {

    if (num == 0) {
        return false;
    }

    for (int i = 0; i < 32; ++i) {

        if (num == (1 << i)) {
            return true;
        }
    }
    
    return false;
}

long long max_pow2(long long val) {

    long long res = 1;

    while ( ( res << 1 ) <= val ) {
        res <<= 1;
    }

    return res;

}


long long get(long long x, long long y) {

    if (x == y) {
        return 0;
    }
    if (x > y) {
        return get(y, x) ;
    }

    if (x == 0) {
        return y;
    }

    if (y == 0) {
        return x;
    }

    long long mp = max_pow2(y);

    if (y == mp) {

        if (x < mp) {
            return mp + x;
        }

        else {
            return x - mp;
        }
    }

    else {

        long long d = y - mp;

        if (x < mp) {
            return mp + get(d, x);
        }
        else {
            return get(d, x) - mp;
        }

    }

}

long long getX(long long y, long long c);

long long getY(long long x, long long c) {

   // std::cout << x << " " << c << std::endl;

    if (c == 0) {
        return x;
    }

    if (x == c) {
        return 0;
    }

    long long mp = std::max( max_pow2(c), max_pow2(x) );


    if (x < mp && c >= mp) {

        return mp + getY(x, c - mp);
    }
    else if (x >= mp && c >= mp) {

        return getY(x-mp, c - mp);
    }
    else if ( x >= mp && c < mp ) {

        return mp + getY(x-mp, c);
    }
    else  {
        assert( false ) ;
    }

}


int main() {

    long long x, y;

    std::cin >> x >> y;

    std::cout << get(x, y) << std::endl;


    long long x2, c;

    std::cin >> x2 >> c;

    std::cout << getY(x2, c) << std::endl;

    return 0;
}