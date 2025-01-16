#include <iostream>
#include <unordered_set>



int main() {

	int N;
	std::cin >> N;

	std::unordered_set<int> positions;

	for (int i = 0; i < N; ++i) {

		int a, b;
		std::cin >> a >> b;

		if (a + b == N - 1 && a >= 0 && b >= 0) {

			positions.insert(a + 1);
		}
	}

	std::cout << positions.size() << std::endl;

}