#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {

	long long N;
	std::cin >> N;

	std::vector<long long> x(N);

	for (int i = 0; i < N; ++i) {

		std::cin >> x[i];
	}

	long long leftSum = 0;
	long long rightSum = 0;

	for (int i = 1; i < N; ++i) {

		rightSum += x[i] - x[0];
	}

	long long lc = 0;
	long long rc = N - 1;

	long long best_sum = rightSum;
	long long best_coord = x[0];

	for (int i = 1; i < N; ++i) {

		++lc;

		leftSum += (x[i] - x[i - 1]) * lc;	
		rightSum -= (x[i] - x[i - 1]) * rc;
		--rc;

		long long total_sum = leftSum + rightSum;

		if (total_sum < best_sum) {
			best_sum = total_sum;
			best_coord = x[i];
		}
	}

	std::cout << best_coord << std::endl;


	return 0;
}