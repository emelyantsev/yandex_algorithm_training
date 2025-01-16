#include <iostream>
#include <unordered_set>

int main() {

	std::unordered_set<int> px;

	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i) {

		int x, y;
		std::cin >> x >> y;
		px.insert(x);
	}

	std::cout << px.size() << std::endl;


	


}
