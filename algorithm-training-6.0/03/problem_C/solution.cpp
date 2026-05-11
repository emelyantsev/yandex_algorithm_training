#include <iostream>
#include <map>
#include <vector>

int main() {

    int n, k;

    std::cin >> n >> k;

    std::vector<int> nums;

    for (int i = 0; i < n; ++i) {

        int num;
        std::cin >> num;
        nums.push_back(num); 
    }

    std::map<int, int> window;

    for (int i = 0 ; i < k; ++i) {

        window[nums[i]] += 1;
    }

    std::cout << window.begin()->first << std::endl;

    for (int i = k; i < n; ++i) {

        window[nums[i-k]] -= 1;

        if (window[nums[i-k]] == 0) {

            window.erase(nums[i-k]);
        }

        window[nums[i]] += 1;

        std::cout << window.begin()->first << std::endl;
    }


    return 0;
}