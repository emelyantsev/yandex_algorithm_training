#include <iostream>

int main() {

	bool is_const = true;
	bool is_asc = true;
	bool is_weak_asc = true;
	bool is_dsc = true;
	bool is_weak_dsc = true;

	int prev;

	std::cin >> prev;

	while (true) {

		int next;
		std::cin >> next;

		if (next == -2000000000) {
			break;
		}

		if (is_const) {

			if (next != prev) {
				is_const = false;
			}
		}

		if (is_asc) {

			if (next <= prev) {
				is_asc = false;
			}
		}

		if (is_weak_asc) {

			if (next < prev) {
				is_weak_asc = false;
			}
		}

		if (is_dsc) {

			if (next >= prev) {
				is_dsc = false;
			}
		}


		if (is_weak_dsc) {

			if (next > prev) {
				is_weak_dsc = false;
			}
		}

		prev = next;
	}

	if (is_const) {
		std::cout << "CONSTANT" << std::endl;
	}
	else if (is_asc) {
		std::cout << "ASCENDING" << std::endl;
	}
	else if (is_weak_asc) {
		std::cout << "WEAKLY ASCENDING" << std::endl;
	}
	else if (is_dsc) {
		std::cout << "DESCENDING" << std::endl;
	}
	else if (is_weak_dsc) {
		std::cout << "WEAKLY DESCENDING" << std::endl;
	}
	else {
		std::cout << "RANDOM" << std::endl;
	}

}