 #include <vector>
#include <iostream>
#include <unordered_map>

int main() {

	int S;
	std::cin >> S;

	std::vector<int> a, b, c;

	int n;
	std::cin >> n;

	a.resize(n);
	for (int i = 0; i < n; ++i) {

		std::cin >> a[i];
	}

	std::cin >> n;

	b.resize(n);
	for (int i = 0; i < n; ++i) {

		std::cin >> b[i];
	}

	std::cin >> n;
	c.resize(n);

	std::unordered_map<int, int> c_items;

	for (int i = 0; i < n; ++i) {

		std::cin >> c[i];

		if (c_items.count(c[i]) == 0) {
			c_items[c[i]] = i;
		}
	}

	for (int i = 0; i < a.size(); ++i) {

		for (int j = 0; j < b.size(); ++j) {

			int sum_ab = a[i] + b[j];

			int rem = S - sum_ab;

			if (c_items.count(rem)) {

				std::cout << i << " " << j << " " << c_items[rem] << std::endl;

				return 0;
			}
		}
	}

	
	std::cout << -1 << std::endl;


	return 0;
}