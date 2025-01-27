#include <string>
#include <iostream>


int main() {

	std::string s;
	std::cin >> s;

	int open_count = 0;
	int close_count = 0;

	for (char c : s) {


		if (c == '(') {
			++open_count;
		}
		else {
			++close_count;
		}

		if (close_count > open_count) {
			std::cout << "NO" << std::endl;
			return 0;
		} 
	}

	if (close_count != open_count) {
		std::cout << "NO" << std::endl;
	}
	else {
		std::cout << "YES" << std::endl;
	}

	return 0;
}