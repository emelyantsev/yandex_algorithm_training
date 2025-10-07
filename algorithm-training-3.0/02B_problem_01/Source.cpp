#include <iostream>
#include <map>
#include <algorithm>
#include <string>

int main() {

	char c;

	std::map<char, int> counts;

	int max_count = 0;

	std::string line;
	

	while ( getline(std::cin, line) ) {

		
		for (char c : line) {

			if ( !isspace(c) ) {
				++counts[c];
				max_count = std::max(max_count, counts[c]);
			}
		}
	}

	for (int i = 1; i <= max_count; ++i) {

		int j = max_count - i + 1;

		for (const auto& [ch, count] : counts) {

			if (j > count) {
				std::cout << " ";
			}
			else {
				std::cout << "#";
			}
		}

		std::cout << std::endl;
	}

	for (const auto& [ch, _] : counts) {

		std::cout << ch;
	}

	std::cout << std::endl;
}