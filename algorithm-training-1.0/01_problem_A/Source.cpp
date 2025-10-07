#include <string>
#include <iostream>
#include <algorithm>

int main() {

	int tr, tc;
	std::string mode;

	std::cin >> tr >> tc;
	std::cin >> mode;

	int res;

	if (mode == "freeze") {

		res = tc < tr ? tc : tr;
	}
	else if (mode == "heat") {
		res = tc > tr ? tc : tr;
	}
	else if (mode == "auto") {
		res = tc;
	}
	else {
		res = tr;
	}

	std::cout << res << std::endl;

	return 0;
}
