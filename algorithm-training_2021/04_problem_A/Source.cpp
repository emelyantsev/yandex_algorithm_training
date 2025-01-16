#include <iostream>
#include <unordered_map>
#include <string>


int main() {


	int n;
	std::cin >> n;

	std::unordered_map<std::string, std::string> words;

	for (int i = 0; i < n; ++i) {


		std::string w1, w2;
		std::cin >> w1 >> w2;

		words[w1] = w2;
		words[w2] = w1;
	}

	std::string word;
	std::cin >> word;

	std::cout << words[word] << std::endl;

	
}