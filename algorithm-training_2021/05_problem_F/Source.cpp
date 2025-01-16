#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

int main() {

	int n;
	std::cin >> n;

	std::vector<int> a(n);

	for (int i = 0; i < n; ++i) {

		std::cin >> a[i];
	}

	int m;
	std::cin >> m;

	struct Item {
		int b;
		int c;
	};

	std::vector<Item> items(m);

	for (int i = 0; i < m; ++i) {
		std::cin >> items[i].b >> items[i].c;
	}

	std::sort(items.begin(), items.end(), [](const Item& l, const Item& r) {
		
		return l.c < r.c; });


	std::map<int, int> priceToPower;

	for (const Item& item : items) {

		if (priceToPower.size() == 0) {

			priceToPower[item.c] = item.b;
		}
		else {

			auto it = priceToPower.rbegin();

			if (it->first <= item.c && it->second < item.b) {

				priceToPower[item.c] = item.b;
			}
		}
	}


	std::map<int, int> powerToPrice;

	for (const auto& [price, power] : priceToPower) {


		powerToPrice[power] = price;
	}

	int sum = 0;

	for (const int ai : a) {

		int min_sum = powerToPrice.lower_bound(ai)->second;
		sum += min_sum;
	}

	std::cout << sum << std::endl;

}
