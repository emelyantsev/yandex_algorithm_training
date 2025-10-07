#include <iostream>
#include <algorithm>


int main() {


	int a, b, n, m;

	std::cin >> a >> b >> n >> m;

	int t1_min = (a + 1) * (n - 1) + 1;
	int t1_max = t1_min + 2 * a;

	int t2_min = (b + 1) * (m - 1) + 1;
	int t2_max = t2_min + 2 * b;


	int t_min = std::max(t1_min, t2_min);
	int t_max = std::min(t1_max, t2_max);

	if (t_min <= t_max) {
		std::cout << t_min << " " << t_max << std::endl;
	}
	else {
		std::cout << -1 << std::endl;
	}

}