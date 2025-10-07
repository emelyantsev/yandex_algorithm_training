#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <sstream>

class Verifier {

public:

	void Initialize() {

		int n;
		std::string C, D;
		std::cin >> n >> C >> D;

		case_sensitive = (C == "yes" ? true : false);
		can_start_with_digit = (D == "yes" ? true : false);

		for (int i = 0; i < n; ++i) {

			std::string word;
			std::cin >> word;

			if (!case_sensitive) {

				key_words.insert(toLower(word));
			}
			else {
				key_words.insert(word);
			}
		}
	}


	void Process() {

		std::string word;

		std::unordered_map< std::string, int > word_counts;
		std::unordered_map< std::string, int > word_positions;

		int best_count = 0;
		

		std::string input = filter_input();

		std::istringstream stream(input);

		int pos = 0;

		while (stream >> word) {

			std::string word_copy = case_sensitive ? word : toLower(word);

			if (key_words.count(word_copy) == 0 && isIdentifier(word_copy) ) {


				if (word_positions.count(word_copy) == 0) {
					word_positions[word_copy] = pos;
				}

				word_counts[word_copy] += 1;

				if (word_counts[word_copy] > best_count) {

					best_count = word_counts[word_copy];
				}
			}
			++pos;
		}

		std::string best_word;

		for (const auto& [word_, count] : word_counts) {

			if (count == best_count && (best_word == "" || word_positions[word_] < word_positions[best_word]) ) {
				best_word = word_;
			}
		}


		std::cout << best_word << std::endl;
	}

private:

	std::string toLower(std::string& str) {

		std::string str_copy = str;

		for (int i = 0; i < str_copy.size(); ++i) {

			str_copy[i] = std::tolower(str_copy[i]);
		}

		return str_copy;
	}

	bool isIdentifier(const std::string& word) {

		if (std::isdigit(word[0]) && !can_start_with_digit) {
			return false;
		}

		bool has_no_digit = false;

		for (char c : word) {

			if (!std::isdigit(c) && !std::isalpha(c) && (c != '_') ) {
				return false;
			}

			if ( std::isalpha(c) || (c == '_') ) {
				has_no_digit = true;
			}

		}

		return has_no_digit;
	}

	std::string filter_input() {

		std::string result;

		int c;

		while ( ( c = getchar() ) != EOF) {

			if (!std::isdigit(c) && !std::isspace(c) && !std::isalpha(c) && (c != '_')) {
				result.push_back(' ');
			}
			else {
				result.push_back(c);
			}

		}

		return result;
	}


	bool case_sensitive;
	bool can_start_with_digit;

	std::unordered_set<std::string> key_words;

};

int main() {

	Verifier verifier;

	verifier.Initialize();
	verifier.Process();


}