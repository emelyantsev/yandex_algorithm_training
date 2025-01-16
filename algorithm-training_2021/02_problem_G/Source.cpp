#include <iostream>
#include <algorithm>
#include <climits>


int main() {

	long long max1 = LLONG_MIN;
	long long max2 = LLONG_MIN;

	long long min1 = LLONG_MAX;
	long long min2 = LLONG_MAX;

	long long num;

	while (std::cin >> num) {


		if (num >= max1) {
			max2 = max1;
			max1 = num;
		}
		else if (num > max2) {
			max2 = num;
		}

		if (num <= min1) {
			min2 = min1;
			min1 = num;
		}
		else if (num < min2 ){

			min2 = num;
		}
	}


	if (max1 * max2 > min1 * min2) {
		std::cout << max2 << " " << max1 << std::endl;
	}
	else {
		std::cout << min1 << " " << min2 << std::endl;
	}




}
