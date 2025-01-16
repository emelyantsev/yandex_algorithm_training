#include <string>
#include <iostream>
#include <unordered_set>

int main() {

	int x, y, z;
	std::cin >> x >> y >> z;

	std::unordered_set<int> digits{x,y,z};

	std::string num;
	std::cin >> num;

	for (char c : num) {

		int d = c - '0';

		digits.insert(d);
	}

	std::cout << digits.size() - 3 << std::endl;

}
