#include <string>
#include <iostream>
#include <unordered_set>

int main() {

	std::string word;

	std::unordered_set<std::string> words;

	while (std::cin >> word) {

		words.insert(word);
	}

	std::cout << words.size() << std::endl;


}