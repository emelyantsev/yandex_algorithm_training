#include <iostream>
#include <vector>
#include <algorithm>



int main() {

	int n;
	std::cin >> n;

	std::vector<int> key_counts;
	key_counts.reserve(n);

	for (int i = 0; i < n; ++i) {

		int c;
		std::cin >> c;
		key_counts.push_back(c);
	}

	int k;
	std::cin >> k;

	for (int i = 0; i < k; ++i) {

		int p;
		std::cin >> p;

		--key_counts[p - 1];
	}

	auto print = [](const int& n) {std::cout << (n >= 0 ? "NO" : "YES") << std::endl; };

	std::for_each(key_counts.cbegin(), key_counts.cend(), print);

}
