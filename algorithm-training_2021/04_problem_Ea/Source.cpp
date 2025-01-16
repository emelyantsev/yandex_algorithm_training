#include <iostream>
#include <unordered_map>


int main() {

	int n;
	std::cin >> n;

	std::unordered_map<int, int> blocks;

	for (int i = 0; i < n; ++i) {

		int w, h;
		std::cin >> w >> h;

		if (blocks[w] < h) {
			
			blocks[w] = h;
		}

	}

	long long result = 0;

	for (const auto& [w, h] : blocks) {

		result += h;
	}

	std::cout << result << std::endl;

}