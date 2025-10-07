#include <iostream>
#include <algorithm>
#include <climits>

bool is_good(long long a, long long b, long long c, long long d) {

	long long n = a + b + c + d;

	long long left = 20 * a + 30 * b + 40 * c + 50 * d;
	long long right = 35 * n;

	return 20 * a + 30 * b + 40 * c + 50 * d >= 35 * n;
}


int main() {

	long long a, b, c;

	std::cin >> a >> b >> c;

	long long min_d = 0;
	long long max_d = 10000000000000000;


	while (true) {


		long long mid_d = min_d + (max_d - min_d) / 2;

		if (!is_good(a, b, c, mid_d)) {
			min_d = mid_d + 1;
		}
		else {

			if (mid_d == 0 || !is_good(a, b, c, mid_d - 1)) {
				std::cout << mid_d << std::endl;
				break;
			}
			else {

				max_d = mid_d - 1;
			}


		}


	}

	return 0;
}
