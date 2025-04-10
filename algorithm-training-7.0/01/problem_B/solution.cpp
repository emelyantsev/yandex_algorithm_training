#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>
#include <climits>
#include <algorithm>

void Solve() {

    int n;
    std::cin >> n;

    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {

        std::cin >> a[i];
    }

    std::vector<int> ans;

    int curr_len = 0;
    int curr_min = INT_MAX;

    for (int i = 0; i < n; ++i) {

        if (curr_len == 0) {
            curr_len = 1;
            curr_min = a[i];
        }
        else {
            curr_min = std::min(curr_min, a[i]);
            ++curr_len;
        }

        if (curr_len == curr_min || i == n - 1 || a[i+1] < curr_len + 1 ) {

            ans.push_back(curr_len);
            curr_len = 0;
        }
    }

    std::cout << ans.size() << std::endl;

    for (int i = 0; i < ans.size(); ++i) {

        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
}



int main() {

    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {

        Solve();
    }

    return EXIT_SUCCESS;
}