#include <iostream>
#include <unordered_set>

int main() {

	int num;
	std::unordered_set<int> nums;

	while (std::cin >> num) {

		nums.insert(num);
	}

	std::cout << nums.size() << std::endl;




}