#include <iostream>
#include <map>
#include <vector>

int main() {

	int n, k;
	std::cin >> n >> k;

	std::map<int, int> num_counts;

	for (int i = 0; i < n; ++i) {

		int x;
		std::cin >> x;
		num_counts[x] += 1;
	}

	std::vector<int> nums;
	nums.reserve(num_counts.size());

	for (const auto& [x, _] : num_counts) {
		nums.push_back(x);
	}

	long long answer = 0;

	// aaa

	for (const auto& [x, count] : num_counts) {
		if (count >= 3) {
			++answer;
		}
	}


	// a b c

	int l = 0;
	int r = 1;

	while (true) {

		long long max_num = static_cast<long long>(nums[l]) * k;

		while (r < nums.size() && nums[r] <= max_num) {
			++r;
		}

		int diff = r - l;

		if (diff >= 3) {

			answer += static_cast<long long>(diff - 1) * (diff - 2) * 3;
		}

		++l;

		if (l == nums.size()) {
			break;
		}
	}

	// a a b

	l = 0;
	int m = 0;
	r = 1;

	while (true) {

		while (m < nums.size() && num_counts[nums[m]] < 2) {
			++m;
		}

		if (m == nums.size()) {
			break;
		}

		while (static_cast<long long>(nums[l]) * k < nums[m]) {
			++l;
		}

		r = m + 1;

		while (r < nums.size() && static_cast<long long>(nums[m]) * k >= nums[r]) {
			++r;
		}

		int less_diff = m - l;

		answer += static_cast<long long>(less_diff) * 3;

		int more_diff = r - m - 1;

		answer += static_cast<long long>(more_diff) * 3;

		++m;
	}


	std::cout << answer << std::endl;
}
