#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>
#include <iomanip>

int main() {

	double min = 30.;
	double max = 4000.;

	int n;
	std::cin >> n;

	double prev;

	std::cin >> prev;

	for (int i = 0; i < n - 1; ++i) {


		double next;
		std::string cmp;

		std::cin >> next >> cmp;

		if (prev == next) {
			continue;
		}

		if (cmp == "further") {

			if (prev < next) {

				double pos_max = prev + (next - prev) / 2;
				max = std::min(max, pos_max);
			}
			else {
				double pos_min = next + (prev - next) / 2;
				min = std::max(min, pos_min);
			}
		}
		else {

			if (prev < next) {

				double pos_min = prev + (next - prev) / 2;
				min = std::max(min, pos_min);
			}
			else {
				double pos_max = next + (prev - next) / 2;
				max = std::min(max, pos_max);
			}
		}

		prev = next;
	}

	std::cout << std::setprecision(7) << min << " " << max << std::endl;

}