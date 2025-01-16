#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cctype>
#include <cassert>


class Verifier {
	
public:

	void BuildDictionary() {

		int N;
		std::cin >> N;

		for (int i = 0; i < N; ++i) {

			std::string word;
			std::cin >> word;

			int pos = getUpperPos(word);

			toLower(word);

			dict[word].insert(pos);
		}
	}

	bool Verify(const std::string& word) {

		std::string wordCopy = word;

		toLower(wordCopy);

		if (dict.count(wordCopy) == 0 && hasOneUpper(word)) {
			return true;
		}

		if (dict.count(wordCopy) == 1 && hasOneUpper(word) && dict[wordCopy].count(getUpperPos(word)) == 1) {
			return true;
		}

		return false;
	}

private:

	int getUpperPos(const std::string& str) {

		for (int i = 0; i < str.size(); ++i) {

			if (std::isupper(str[i])) {
				return i;
			}
		}

		assert(false);
	}

	void toLower(std::string& str) {

		for (int i = 0; i < str.size(); ++i) {
			str[i] = std::tolower(str[i]);
		}
	}


	bool hasOneUpper(const std::string& str) {

		int count = 0;

		for (int i = 0; i < str.size(); ++i) {

			if (std::isupper(str[i])) {
				++count;
			}
		}

		return count == 1;
	}



	std::unordered_map<std::string, std::unordered_set<int> > dict;

};



int main() {

	Verifier verifier;

	verifier.BuildDictionary();

	std::string word;
	int count = 0;

	while (std::cin >> word) {

		if (!verifier.Verify(word)) {
			++count;
		}

	}
	
	std::cout << count << std::endl;
}