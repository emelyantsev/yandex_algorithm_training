#include <iostream>


int main() {

	int a, b, c;

	
	std::cin >> a >> b >> c;

	if (c < 0) {

		std::cout << "NO SOLUTION" << std::endl;
	}
	else {

		int d = c * c - b;

		if (a == 0 && d == 0) {

			std::cout << "MANY SOLUTIONS" << std::endl;
		}
		else if (a == 0 && d != 0) {
			std::cout << "NO SOLUTION" << std::endl;
		}
		else {

			if (d % a == 0) {
				std::cout << d / a << std::endl;
			}
			else {
				std::cout << "NO SOLUTION" << std::endl;
			}


		}

	}

	return 0;
}