#include <iostream>
#include <algorithm>


long long get_count(long long w, long long h, long long a) {

	return (a / w) * (a / h);
}


int main() {


	long long w, h, n;
	std::cin >> w >> h >> n;

	long long max_a = std::max(w, h) * n;
	long long min_a = 1;

	while (true) {


		long long mid_a = min_a + (max_a - min_a) / 2;

		long long mid_count = get_count(w, h, mid_a);

		if (mid_count < n) {

			min_a = mid_a + 1;
		}
		else {

			long long less_count = get_count(w, h, mid_a - 1);

			if (less_count < n) {
				std::cout << mid_a << std::endl;
				break;
			}
			else {
				max_a = mid_a - 1;
			}
		}

	}
	

	return 0;
}