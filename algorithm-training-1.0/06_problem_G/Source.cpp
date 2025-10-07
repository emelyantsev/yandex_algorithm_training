#include <iostream>
#include <algorithm>

long long get_count(long long n, long long m, long long d) {

	return 2 * (n * d) + 2 * (m - 2 * d) * d;
}


int main() {

	long long n, m;
	long long t;

	std::cin >> n >> m >> t;

	long long min = 0;
	long long max = std::min(n, m) / 2;


	while (true) {

		long long mid = min + (max - min) / 2;

		long long count = get_count(n, m, mid);

		if (count > t) {

			max = mid - 1;
		}
		else {

			if (get_count(n, m, mid + 1) > t || mid == max) {
				
				std::cout << mid << std::endl;
				break;
			}
			else {
				min = mid + 1;
			}
		}
	}

	return 0;
}