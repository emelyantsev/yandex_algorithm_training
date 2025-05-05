#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

int main() {

    int N, M;
    std::cin >> N >> M;

    std::vector<int> w(N);

    for (int i = 0; i < N; ++i) {

        std::cin >> w[i];
    }

    std::vector<int> c(N);

    for (int i = 0; i < N; ++i) {

        std::cin >> c[i];
    }


    std::vector<int> dp(M+1, -1);
    dp[0] = 0;

    int ans = 0;

    for (int i = 0; i < N; ++i) {

        for (int j = M - w[i]; j >= 0; --j) {

            if (dp[j] != -1) {

                dp[ j + w[i] ]  = std::max( dp[ j + w[i] ], dp[j] + c[i]);
                ans = std::max(ans, dp[ j + w[i] ]) ;
            }
        }
    }

    std::cout << ans << std::endl;


    return EXIT_SUCCESS;
}