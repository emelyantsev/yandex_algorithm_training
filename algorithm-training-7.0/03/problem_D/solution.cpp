#include <iostream>
#include <cstdlib>
#include <algorithm>

int main() {

    int n;
    std::cin >> n;

    int len = 0;
    int x = n;

    while (x != 0) {

        x >>= 1;
        ++len;
    }

    int ans = n;

    for (int i = 0; i < len - 1; ++i) {

        n = (n >> 1) | ( (n & 1) << ( len - 1) ) ;

        ans = std::max(ans, n);
    }

    std::cout << ans << std::endl;


    return EXIT_SUCCESS;
}