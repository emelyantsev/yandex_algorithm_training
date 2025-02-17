#include <queue>
#include <iostream>


int main() {

	std::queue<int> q1, q2;

	for (int i = 0; i < 5; ++i) {

		int num;
		std::cin >> num;
		q1.push(num);
	}

	for (int i = 0; i < 5; ++i) {

		int num;
		std::cin >> num;
		q2.push(num);
	}

	for (int i = 0; i < 1000000; ++i) {

		int num1 = q1.front();
		int num2 = q2.front();

		q1.pop();
		q2.pop();

		if (num1 > num2 &&  !( num1 == 9 && num2 == 0) || ( num1 == 0 && num2 == 9) ) {

			q1.push(num1);
			q1.push(num2);

			if (q2.empty()) {
				std::cout << "first " << i + 1 << std::endl;
				return 0;
			}
		}
		else if (num2 > num1 && !( num2 == 9 && num1 == 0 )  || ( num2 == 0 && num1 == 9) ) {

			q2.push(num1);
			q2.push(num2);

			if (q1.empty()) {
				std::cout << "second " << i + 1 << std::endl;
				return 0;
			}
		}
	}

	std::cout << "botva" << std::endl;

}
