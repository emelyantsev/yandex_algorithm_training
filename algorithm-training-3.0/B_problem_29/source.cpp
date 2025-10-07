#include <cstdlib>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

int main() {

    int N;
    std::cin >> N;

    std::vector<int> costs(N, 0);

    for (int i = 0; i < N; ++i) {
        std::cin >> costs[i];
    }

    std::vector< std::vector<int> > dp(N+1, std::vector<int>(N+1, INT_MAX) ) ;
    std::vector< std::vector<bool> > dp_use_coupon(N+1, std::vector<bool>(N+1, false) ) ;
    
    int K1 = 0;
    int K2 = 0;
    int sum = 0;

    std::vector<int> nums;

    dp[0][0] = 0;

    for (int i = 0; i < N; ++i) {

        for (int j = 0; j <= N; ++j)  {


            if (dp[i][j] == INT_MAX) {
                continue;
            }

            int coupon_count = j;

            int total_sum = dp[i][j] + costs[i]; 

            bool get_coupon = costs[i] > 100 ? true : false;

            if (get_coupon &&  total_sum < dp[i+1][j+1]) {
                dp[i+1][j+1] = total_sum;
            }
            else if (!get_coupon && total_sum < dp[i+1][j]) {
                dp[i+1][j] = total_sum;
            }

            if (coupon_count > 0 ) {

                int total_sum = dp[i][j]; 

                if (total_sum < dp[i+1][j-1]) {
                    dp[i+1][j-1] = total_sum;
                    dp_use_coupon[i+1][j-1] = true;
                }

            }
        }
    }

    int final_count = 0;
    int best_sum = dp[N][0];


    for (int j = 1; j <= N; ++j) {

        if (dp[N][j] <= best_sum) {

            best_sum = dp[N][j];
            final_count = j;
        }
    }

    int j = final_count;
    K1 = final_count;

    for (int i = N; i > 0; --i) {


        if ( dp_use_coupon[i][j] ) {
            nums.push_back(i);
            ++j;
            ++K2;
        }
        else {

            if ( costs[i-1] > 100 ) {
                --j;
            }
        }
    }

    std::cout << best_sum << std::endl;
    std::cout << K1 << " " << K2 << std::endl;

    std::reverse(nums.begin(), nums.end());

    for (int num : nums) {
        std::cout << num << std::endl;
    }

    return EXIT_SUCCESS;
}