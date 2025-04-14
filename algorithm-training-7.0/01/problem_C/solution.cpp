#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <algorithm>

int main() {

    long long M;

    std::cin >> M;

    std::vector<long long> costs(31, 1);

    std::vector<long long> a(31);


    for (int i = 0; i < 31; ++i) {

        std::cin >> a[i];
    }

    for (int i = 1; i < 31; ++i) {

        costs[i] = 2 * costs[i-1];
    }

    for (int i = 1; i < 31; ++i) {

        a[i] = std::max( 2* a[i-1], a[i]);
    }

    long long best_cost = LLONG_MAX;

    long long rem_cost = 0;
    long long rem_time = M;

    for (int i = 30; i >= 0; --i) {

        long long cnt = rem_time / a[i] ;

        long long rem_cnt = rem_time % a[i] == 0 ? 0 : 1;
        long long curr_cost = rem_cost + (cnt + rem_cnt) * costs[i];

        best_cost = std::min(curr_cost, best_cost);

        if (rem_cnt == 0) {
            break;
        }
        else {

            rem_time -= cnt * a[i];
            rem_cost += cnt * costs[i];
        }
    }

    std::cout << best_cost << std::endl;


    return EXIT_SUCCESS;
}