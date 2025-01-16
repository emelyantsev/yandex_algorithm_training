#include <iostream>
#include <algorithm>
#include <cassert>

int get_count(int t, int a, int b) {

	return t / a + t / b;
}

int main() {

	int N, x, y;

	std::cin >> N >> x >> y;

	int a, b;

	a = std::min(x, y);
	b = std::max(x, y);

	if (N == 1) {

		std::cout << a << std::endl;
		return 0;
	}

	int t_min = 1;
	int t_max = (N - 1) * a;

	int need = N - 1;

	while (true) {

		int t_mid = t_min + (t_max - t_min) / 2;

		int count = get_count(t_mid, a, b);

		if (count < need) {

			t_min = t_mid + 1;
		}
		else {

			if ( get_count(t_mid - 1, a, b) < need ) {

				std::cout << t_mid + a << std::endl;
				break;
			}
			else {

				t_max = t_mid - 1;
			}

		}

	}


	return 0;
}