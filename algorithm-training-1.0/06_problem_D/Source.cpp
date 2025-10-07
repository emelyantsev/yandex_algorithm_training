#include <iostream>
#include <algorithm>

bool can_contain(long long a, long long b, long long w, long long h, long long n) {

	return (w / a) * (h / b) >= n || (h / a) * (w / b) >= n;
}

int main() {

	long long n, a, b, w, h;

	std::cin >> n >> a >> b >> w >> h;

	long long d_min = 0;

	long long d_max = std::max(w, h);

	while (true) {

		long long d_mid = d_min + (d_max - d_min) / 2;

		if (!can_contain(a + 2 * d_mid, b + 2 * d_mid, w, h, n)) {

			d_max = d_mid - 1;
		}
		else {

			if (!can_contain(a + 2 * (d_mid + 1), b + 2 * (d_mid + 1), w, h, n)) {

				std::cout << d_mid << std::endl;
				break;
			}
			else {

				d_min = d_mid + 1;
			}
		}

	}



	return 0;
}