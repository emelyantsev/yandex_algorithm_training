#include <iostream>
#include <cstdlib>

int main() {

    long long x;

    std::cin >> x;

    int count = 0;

    while (x != 0) {

        if (x & 1) {
            ++count;
        }

        x >>= 1;
    }

    std::cout << count << std::endl;

    return EXIT_SUCCESS;

}