#include <vector>
#include <iostream>

bool is_symmetric(const std::vector<int>& nums, int from, int to) {

	while (from < to) {
		if (nums[from++] != nums[to--]) {
			return false;
		}
	}

	return true;
}


int main() {

	int n;
	std::cin >> n;

	std::vector<int> nums;
	nums.reserve(n);

	for (int i = 0; i < n; ++i) {

		int num;
		std::cin >> num;
		nums.push_back(num);
	}


	std::vector<int> result;

	for (int i = 0; i < nums.size(); ++i) {

		if (is_symmetric(nums, i, n - 1)) {


			for (int j = i - 1; j >= 0; --j) {

				result.push_back(nums[j]);
			}

			break;
		}

	}

	std::cout << result.size() << std::endl;

	for (int item : result) {

		std::cout << item << " ";
	}


	std::cout << std::endl;


}
