#include <iostream>
#include <algorithm>
#include <vector>

int main() {

	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n);

	for (int i = 0; i < n; ++i) {

		std::cin >> a[i];
	}

	std::sort(a.begin(), a.end());

	for (int i = 0; i < m; ++i) {

		int l, r;
		std::cin >> l >> r;

		auto ir = std::upper_bound(a.begin(), a.end(), r);
		auto il = std::lower_bound(a.begin(), a.end(), l);

		int res = ir - il;

		std::cout << res << std::endl;
	}


	return 0;
}