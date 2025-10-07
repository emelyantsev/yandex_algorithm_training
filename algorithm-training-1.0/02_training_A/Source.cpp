#include <iostream>


int main() {


	int prev;
	std::cin >> prev;

	int current;

	while ( std::cin >> current ) {

		if (current <= prev) {

			std::cout << "NO" << std::endl;
			return 0;
		}
		else {
			prev = current;
		}

	}

	std::cout << "YES" << std::endl;

}