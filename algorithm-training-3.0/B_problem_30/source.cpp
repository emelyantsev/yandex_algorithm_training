#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int N;
    std::cin >> N;

    std::vector<int> a(N);

    for (int i = 0; i < N; ++i) {

        std::cin >> a[i];
    }

    int M;
    std::cin >> M;

    std::vector<int> b(M);

    for (int i = 0; i < M; ++i) {

        std::cin >> b[i];
    }


    std::vector< std::vector<int> > dp(M+1, std::vector<int>(N+1, 0) ) ;

    for (int j = 1; j <= M; ++j) {

        for (int i = 1; i <= N; ++i) {

            if (a[i-1] == b[j-1]) {

                dp[j][i] = std::max( dp[j-1][i-1] + 1, std::max( dp[j-1][i], dp[j][i-1])  )  ;
            }
            else {
                dp[j][i] = std::max( dp[j-1][i], dp[j][i-1]) ;
            }
        }
    }

    std::vector<int> ans;
    ans.reserve(N);

    int i = M;
    int j = N;

    while (true) {

        if (dp[i][j] == dp[i][j-1]) {
            --j;
        }
        else if (dp[i][j] == dp[i-1][j]) {
            --i;
        }
        else {
            ans.push_back(b[i-1]);
            --i;
            --j;
        }

        if (dp[i][j] == 0) {
            break;
        }

    }

    std::reverse(ans.begin(), ans.end());

    for (int ai : ans) {

        std::cout << ai << " ";
    }
    std::cout << std::endl;

    return 0;
}