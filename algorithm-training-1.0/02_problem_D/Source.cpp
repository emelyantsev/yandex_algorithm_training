#include <iostream>
#include <vector>


int main() {

	std::vector<int> nums;

	int num;

	while (std::cin >> num) {

		nums.push_back(num);
	}


	int count = 0;

	for (int i = 1; i < static_cast<int>(nums.size()) - 1; ++i) {

		if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {

			++count;
		}
	}

	std::cout << count << std::endl;
}