#include <iostream>


bool check(int a, int b, int c, int d) {


	if ((a >= c && b >= d) || (a >= d && b >= c)) {
		return true;
	}
	else {
		return false;
	}
}


int main() {

	int a, b, c, d, e;

	std::cin >>  c >> d >> e >> a >> b;


	if (check(a, b, c, d) || check(a, b, c, e) || check(a, b, d, e)) {
		std::cout << "YES" << std::endl;
	} 
	else {
		std::cout << "NO" << std::endl;
	}

	return 0;
}