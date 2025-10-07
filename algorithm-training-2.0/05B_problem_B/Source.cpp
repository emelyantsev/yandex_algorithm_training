#include <iostream>
#include <set>
#include <algorithm>

int main() {

	int n;
	std::cin >> n;

	long long a;
	std::cin >> a;

	long long best_result = a;

	long long curr_sum = a;

	std::set<long long> sums;
	sums.insert(0);
	sums.insert(a);

	for (int i = 1; i < n; ++i) {

		std::cin >> a;
		curr_sum += a;

		long long curr_result = curr_sum - *sums.begin();
		best_result = std::max(best_result, curr_result);
		sums.insert(curr_sum);
	}

	std::cout << best_result << std::endl;

}