#include <vector>
#include <iostream>
#include <cstdlib>


int main() {

    int N;
    std::cin >> N;

    std::vector< std::vector<int> > m(N, std::vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {

        for (int j = 0; j < N; ++j) {

            std::cin >> m[i][j];
        }
    }

    std::vector<int> ans(N, 0);

    for (int i = 0; i < N; ++i) {

        for (int j = i+1; j < N; ++j) {

            int val = m[i][j];

            int count = 0;

            while (val != 0) {

                if (val & 1) {

                    ans[i] |= 1 << count;
                    ans[j] |= 1 << count;
                }

                val >>= 1;
                ++count;
            }

        }

    }

    for (int val : ans) {
        std::cout << val << " ";
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}