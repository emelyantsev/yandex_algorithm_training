#include <iostream>
#include <vector>
#include <algorithm>




int main() {


	int N, K;
	std::cin >> N >> K;

	std::vector<int> nums(N);
	
	for (int i = 0; i < N; ++i) {

		std::cin >> nums[i];
	}


	for (int i = 0; i < K; ++i) {


		int num;
		std::cin >> num;

		if (num <= nums.front() ) {

			std::cout << nums.front() << std::endl;
		}
		else if (num >= nums.back()) {

			std::cout << nums.back() << std::endl;
		}
		else {

			if (nums.size() == 1) {
				std::cout << nums.front() << std::endl;
			}
			else {

				auto low = std::lower_bound( nums.begin(), nums.end(), num );

				if (*low == num) {
					std::cout << num << std::endl;
					continue;
				}
				else {
					--low;
				}

				auto high = std::upper_bound( nums.begin(), nums.end(), num );

				int low_diff = num - *low;
				int high_diff = *high - num;

				if (low_diff <= high_diff) {
					std::cout << *low << std::endl;
				}
				else {
					std::cout << *high << std::endl;
				}

			}

		}

	}


}