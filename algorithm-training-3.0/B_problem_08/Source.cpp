#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main() {

	int K;
	std::cin >> K;

	std::vector<int> x(K);
	std::vector<int> y(K);

	for (int i = 0; i < K; ++i) {

		std::cin >> x[i] >> y[i];

	}

	auto mmx = std::minmax_element(x.begin(), x.end());
	auto mmy = std::minmax_element(y.begin(), y.end());

	std::cout << *mmx.first << " " << *mmy.first << " " << *mmx.second << " " << *mmy.second << std::endl;


	return EXIT_SUCCESS;
}