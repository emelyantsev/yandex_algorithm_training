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

    std::vector<bool> dp(M+1, false);
    dp[0] = true;

    int ans = 0;

    for (int i = 0; i < N; ++i) {

        for (int j = M - w[i]; j >= 0; --j) {

            if (dp[j]) {

                dp[ j + w[i] ]  = true;
                ans = std::max(ans, j + w[i]) ;
            }
        }
    }

    std::cout << ans << std::endl;


    return EXIT_SUCCESS;
}