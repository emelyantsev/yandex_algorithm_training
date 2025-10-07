#include <iostream>
#include <stack>
#include <queue>


int main() {

	int N;
	std::cin >> N;

	std::queue<int> q;
	std::stack<int> s;

	for (int i = 0; i < N; ++i) {

		int num;
		std::cin >> num;
		q.push(num);
	}

	int last_num = 0;

	while (true) {

		int needed = last_num + 1;

		if (!s.empty() && s.top() == needed) {
			s.pop();
			++last_num;

			if (last_num == N) {
				break;
			}

		}
		else {

			if (!q.empty()) {
				
				s.push(q.front());
				q.pop();
			}
			else {
				std::cout << "NO" << std::endl;
				return 0;
			}

		}

	}

	std::cout << "YES" << std::endl;
}

