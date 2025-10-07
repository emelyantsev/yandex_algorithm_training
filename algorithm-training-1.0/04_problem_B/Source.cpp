#include <iostream>
#include <string>
#include <unordered_map>


int main() {

	std::unordered_map<std::string, int> word_counts;

	std::string word;

	while (std::cin >> word) {

		std::cout << word_counts[word]++ << " ";
	}

	std::cout << std::endl;


}