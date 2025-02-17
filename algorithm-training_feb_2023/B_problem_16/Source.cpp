#include <queue>
#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>

template<typename T>
class VerboseQueue : public std::queue<T> {

public:

	void push(const T& val) {

		std::queue<T>::push(val);
		std::cout << "ok\n";
	}

	void pop() {

		if (std::queue<T>::empty()) {
			std::cout << "error\n";
		}
		else {
			std::cout << std::queue<T>::front() << std::endl;
			std::queue<T>::pop();
		}
	}

	T& front() {

		if (std::queue<T>::empty()) {
			throw std::out_of_range("error");
		}
		else {
			return std::queue<T>::front();
		}

	}

	void Clear() {

		static_cast<std::queue<T>&>(*this) = std::queue<T>{};
		std::cout << "ok" << std::endl;
	}

};




int main() {


	VerboseQueue<int> q;

	std::string command;
	
	while (true) {

		std::cin >> command;

		if (command == "push") {

			int val;
			std::cin >> val;
			q.push(val);
		}
		else if (command == "pop") {

			q.pop();
		}
		else if (command == "front") {

			try {

				std::cout << q.front() << std::endl;
			}
			catch (std::out_of_range& e) {
				std::cout << e.what() << std::endl;
			}
		}
		else if (command == "clear") {
			q.Clear();
		}
		else if (command == "size") {
			std::cout << q.size() << std::endl;
		}
		else if (command == "exit") {
			std::cout << "bye\n";
			break;
		}


	}


	return EXIT_SUCCESS;
}