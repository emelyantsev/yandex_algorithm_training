#include <iostream>
#include <string>
#include <unordered_map>


int main() {

	int g;
	int S;

	std::cin >> g >> S;

	std::string w;
	std::cin >> w;

	std::unordered_map<char, int> char_counts;

	for (char c : w) {

		char_counts[c] += 1;
	}

	int result = 0;

	std::string str;
	std::cin >> str;

	std::unordered_map<char, int> window;

	for (int i = 0; i < g; ++i) {

		window[str[i]] += 1;
	}

	if (window == char_counts) {
		++result;
	}

	for (int i = g; i < S; ++i) {

		window[str[i - g]] -= 1;

		if (window[str[i - g]] == 0) {
			window.erase(str[i - g]);
		}

		window[str[i]] += 1;

		if (window == char_counts) {
			++result;
		}
	}

	std::cout << result << std::endl;

}