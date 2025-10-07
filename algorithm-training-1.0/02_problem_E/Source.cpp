#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>


int main() {


	int n;
	std::cin >> n;

	std::vector<int> nums;
	nums.reserve(n);


	int win_res = -1;
	int win_res_ind = -1;


	for (int i = 0; i < n; ++i) {

		int num;
		std::cin >> num;

		nums.push_back(num);

		if (num > win_res) {
			win_res = num;
			win_res_ind = i;
		}
	}


	bool is_found = false;
	int best_res = -1;

	for (int i = 1; i < nums.size() - 1; ++i) {


		if (nums[i] % 10 == 5 && nums[i] > nums[i + 1] && i > win_res_ind) {

			if (!is_found) {
				best_res = nums[i];
				is_found = true;
			}
			else {
				best_res = std::max(best_res, nums[i]);
			}

		}

	}


	if (!is_found) {
		std::cout << 0 << std::endl;
	}
	else {

		std::sort(nums.begin(), nums.end(), std::greater<int>{} );

		auto it = std::lower_bound(nums.begin(), nums.end(), best_res, std::greater<int>{});

		int res = it - nums.begin() + 1;

		std::cout << res << std::endl;

	}

}