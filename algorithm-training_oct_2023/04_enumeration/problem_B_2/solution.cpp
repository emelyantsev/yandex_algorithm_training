#include <vector>
#include <iostream>
#include <algorithm>


bool check_placing(const std::vector<int>& rows, int n) {

    const int N = rows.size();

    for (int i = 0; i < n; ++i) {

        int r1 = rows[i];
        int c1 = i;
        int r2 = rows[n];
        int c2 = n;  

        int dl1 = r1+c1;
        int dl2 = r2+c2;

        if (dl1 == dl2 ) {
            return false;
        }

        int dr1 = r1 + (N - c1 + 1);
        int dr2 = r2 + (N - c2 + 1);  

        if (dr1 == dr2 ) {
            return false;
        }
    }

    return true;
}


void generate(std::vector<int>& nums, int l, int r, int& ans) {

    if (l == r) {

        if (check_placing(nums, l)) {
            ++ans;
        }

        // for (int num : nums) {
        //     std::cout << num << " ";
        // }
        // std::cout << std::endl;
    }
    else {

        for (int i = l ; i < r+1; ++i) {

            std::swap(nums[l], nums[i]);

            if (check_placing(nums, l)) {

                generate(nums, l+1, r, ans);
            }

            std::swap(nums[i], nums[l]);
        }
    }
}





int main() {

    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i;
    }

    int ans = 0;

    generate(nums, 0, n-1, ans);

    std::cout << ans << std::endl;


    return 0;
}