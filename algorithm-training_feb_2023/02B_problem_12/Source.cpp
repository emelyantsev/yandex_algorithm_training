#include <iostream>
#include <string>
#include <stack>


int main() {

	std::string s;
	std::cin >> s;

	std::stack<char> stack;


	for (char c : s) {

		if (c == '(' || c == '[' || c == '{') {
			stack.push(c);
		}
		else if (c == ')') {

			if (stack.empty() || stack.top() != '(') {
				std::cout << "no" << std::endl;
				return 0;
			}
			else {
				stack.pop();
			}
		}
		else if (c == ']') {

			if (stack.empty() || stack.top() != '[') {
				std::cout << "no" << std::endl;
				return 0;
			}
			else {
				stack.pop();
			}
		}
		else // c == '}' 
		{
			if (stack.empty() || stack.top() != '{') {
				std::cout << "no" << std::endl;
				return 0;
			}
			else {
				stack.pop();
			}
		}
	}


	std::cout << (stack.empty() ? "yes" : "no") << std::endl;


	return 0;
}