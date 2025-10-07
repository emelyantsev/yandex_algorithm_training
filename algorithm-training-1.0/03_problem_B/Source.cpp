#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <set>


int main() {

	std::string l1, l2;

	std::getline(std::cin, l1);
	std::getline(std::cin, l2);

	std::istringstream s1(l1);
	std::istringstream s2(l2);

	std::unordered_set<int> nums1;

	int num;

	while (s1 >> num) {
		nums1.insert(num);
	}

	std::set<int> result;

	while (s2 >> num) {
		
		if (nums1.count(num) == 1) {
			
			result.insert(num);
		}
	}


	for (int r : result) {
		std::cout << r << " ";
	}

	std::cout << std::endl;

}
