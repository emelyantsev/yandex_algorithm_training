#include <iostream>
#include <unordered_map>
#include <string>


int main() {


	std::unordered_map<std::string, int> word_count;

	std::string best_word;
	std::cin >> best_word;

	int best_count = 1;

	word_count[best_word] = 1;


	std::string word;

	while (std::cin >> word) {

		int count = ++word_count[word];

		if (best_count < count || (best_count == count && word < best_word ) ) {
			best_count = count;
			best_word = word;
		}

	}

	std::cout << best_word << std::endl;



}