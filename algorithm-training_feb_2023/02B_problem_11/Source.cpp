#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
#include <string>

template<typename T>
class VerboseVector : public std::vector<T> {

public:

	T& back() {

		std::cout << std::vector<T>::back() << std::endl;
		return std::vector<T>::back();
	}

	void push_back(const T& value) {
		std::vector<T>::push_back(value);
		std::cout << "ok\n";
	}

	void pop_back() {

		std::cout << std::vector<T>::back() << std::endl;
		std::vector<T>::pop_back();
	}

	VerboseVector<T>& operator=(VerbouseVector<T>&& other) {
		std::cout << "ok\n";
		std::vector<T>::operator=( other ) ;
		return *this;
	}

};



int main() {

	std::stack<int, VerboseVector<int>> stack;

	while (true) {

		std::string command;
		std::cin >> command;

		if (command == "push") {

			int val;
			std::cin >> val;
			stack.push(val);
		}
		else if (command == "pop") {

			if (stack.empty()) {
				std::cout << "error\n";
			}
			else {
				stack.pop();
			}
		}
		else if (command == "back") {

			if (stack.empty()) {
				std::cout << "error\n";
			}
			else {
				stack.top();
			}

		}
		else if (command == "size") {
			std::cout << stack.size() << std::endl;
		}
		else if (command == "clear") {
			stack = {};
		}
		else if (command == "exit") {
			std::cout << "bye\n";
			break;
		}

	}


	return EXIT_SUCCESS;
}