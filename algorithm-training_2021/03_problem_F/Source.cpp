#include <iostream>
#include <string>
#include <unordered_set>

int main() {

	std::string g1, g2;
	std::cin >> g1 >> g2;

	std::unordered_set<std::string> p2;

	for (int i = 0; i < g2.size() - 1; ++i) {

		std::string p = g2.substr(i, 2);

		p2.insert(p);
	}

	int count = 0;

	for (int i = 0; i < g1.size() - 1; ++i) {

		std::string p = g1.substr(i, 2);

		if (p2.count(p) == 1) {
			++count;
		}
	}

	std::cout << count << std::endl;

}