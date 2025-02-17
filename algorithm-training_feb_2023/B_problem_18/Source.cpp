#include <iostream>
#include <string>
#include <deque>


template <typename T>
class VerboseDeque : public std::deque<T> {

public:

	void push_front(const T& val) {

		std::deque<T>::push_front(val);
		std::cout << "ok\n";
	}

	void push_back(const T& val) {
		std::deque<T>::push_back(val);
		std::cout << "ok\n";
	}

	void pop_front() {
		if (std::deque<T>::empty()) {
			std::cout << "error\n";
		}
		else {
			std::cout << std::deque<T>::front() << std::endl;
			std::deque<T>::pop_front();
			
		}
	}

	void pop_back() {
		if (std::deque<T>::empty()) {
			std::cout << "error\n";
		}
		else {
			std::cout << std::deque<T>::back() << std::endl;
			std::deque<T>::pop_back();
			
		}
	}

	T& front() {

		if (std::deque<T>::empty()) {
			throw std::out_of_range("error");
		}
		else {
			return std::deque<T>::front();
		}

	}

	T& back() {

		if (std::deque<T>::empty()) {
			throw std::out_of_range("error");
		}
		else {
			return std::deque<T>::back();
		}

	}

	void clear() {

		std::deque<T>::clear();
		std::cout << "ok\n";
	}
};


int main() {

	VerboseDeque<int> q;

	std::string command; 

	while (true) {

		std::cin >> command;

		if (command == "push_front") {

			int val;
			std::cin >> val;

			q.push_front(val);
		}
		else if (command == "push_back") {

			int val;
			std::cin >> val;
			q.push_back(val);

		}
		else if (command == "pop_front") {
			q.pop_front();
		}
		else if (command == "pop_back") {
			q.pop_back();
		}
		else if (command == "front") {

			try {

				std::cout << q.front() << std::endl;
			}
			catch (std::out_of_range& e) {
				std::cout << e.what() << std::endl;
			}
		}
		else if (command == "back") {

			try {

				std::cout << q.back() << std::endl;
			}
			catch (std::out_of_range& e) {
				std::cout << e.what() << std::endl;
			}
		}
		else if (command == "size") {

			std::cout << q.size() << std::endl;
		}
		else if (command == "clear") {

			q.clear();
		}
 

		else if (command == "exit") {

			std::cout << "bye\n";
			break;
		}


	}





	return 0;
}