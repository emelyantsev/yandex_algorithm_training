#include <iostream>
#include <vector>
#include <algorithm>

int main() {

	int N;
	std::cin >> N;

	std::vector<int> nums;

	for (int i = 0; i < N; ++i) {


		int x, y;
		std::cin >> x >> y;
		nums.push_back(y);
	}

	std::vector<int> sum_left{ 0 };

	int curr_sum = 0;

	for (int i = 1; i < nums.size(); ++i) {

		int diff = std::max(0, nums[i] - nums[i - 1]);
		curr_sum += diff;
		sum_left.push_back(curr_sum);
	}

	std::vector<int> sum_right{ 0 };

	curr_sum = 0;

	for (int i = nums.size()  - 2; i >= 0; --i) {

		int diff = std::max(0, nums[i] - nums[i + 1]);
		curr_sum += diff;
		sum_right.push_back(curr_sum);
	}


	int M;
	std::cin >> M;

	for (int i = 0; i < M; ++i) {

		int s, f;
		std::cin >> s >> f;

		if (s == f) {
			std::cout << 0 << std::endl;
		}
		else if (s < f) {
			--s; --f;
			int res = sum_left[f] - sum_left[s];
			std::cout << res << std::endl;
		}
		else {
			s = N - s ;
			f = N - f;
			int res = sum_right[f] - sum_right[s];
			std::cout << res << std::endl;
		}
	}



}