#include <algorithm>
#include <vector>
#include <iostream>

int main() {

	int N;
	std::cin >> N;

	std::vector<int> nums;
	nums.reserve(N);

	for (int i = 0; i < N; ++i) {

		int inp;
		std::cin >> inp;
		nums.push_back(inp);
	}

	int x;
	std::cin >> x;


	std::cout << *std::min_element( nums.begin(), nums.end(), [x](int lhs, int rhs) { return std::abs(lhs - x) < std::abs(rhs - x); } ) << std::endl;


}