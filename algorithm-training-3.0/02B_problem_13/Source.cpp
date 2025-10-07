#include <iostream>
#include <string>
#include <stack>
#include <cassert>

int main() {

	std::stack<int> vals;

	std::string op;

	while (std::cin >> op) {


		if (op == "+") {

			assert(vals.size() > 1);

			int op1 = vals.top();
			vals.pop();
			int op2 = vals.top();
			vals.pop();

			vals.push(op1 + op2);
		}
		else if (op == "-") {

			assert(vals.size() > 1);

			int op1 = vals.top();
			vals.pop();
			int op2 = vals.top();
			vals.pop();

			vals.push(op2 - op1);
		}
		else if (op == "*") {

			assert(vals.size() > 1);

			int op1 = vals.top();
			vals.pop();
			int op2 = vals.top();
			vals.pop();

			vals.push(op2 * op1);
		}
		else {

			vals.push(std::stoi(op));
		}

	}

	assert(vals.size() == 1);

	std::cout << vals.top() << std::endl;

	return 0;
}