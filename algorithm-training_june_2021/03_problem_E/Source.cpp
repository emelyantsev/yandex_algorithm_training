#include <iostream>
#include <algorithm>
#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <cassert>

class Forum {

public:

	void ParseMessage() {

		std::string line;
		std::getline(std::cin, line);

		std::istringstream s(line);

		int messageId;
		s >> messageId;

		if (messageId == 0) {

			std::string themeName;
			std::getline(std::cin, themeName);

			std::string messageText;
			std::getline(std::cin, messageText);

			knownThemes.push_back(themeName);

			messageThemes.push_back( knownThemes.size() - 1 );
			
			assert( themeCounts.count( knownThemes.back() ) == 0 );

			themeCounts[ knownThemes.back() ] = 1;
		}
		else {

			--messageId;

			std::string messageText;
			std::getline(std::cin, messageText);

			messageThemes.push_back( messageThemes[messageId] );

			assert( themeCounts.count( knownThemes[messageThemes.back()] ) != 0 );

			++themeCounts[ knownThemes[ messageThemes.back() ] ];
		}

	}

	std::string GetHottestTheme() {

		std::string ans = knownThemes.front();

		for (int i = 1; i < knownThemes.size(); ++i) {

			if (themeCounts[knownThemes[i]] > themeCounts[ans] ) {
				ans = knownThemes[i];
			}
		}

		return ans;

	}

private:

	std::vector<std::string> knownThemes;
	std::vector<int> messageThemes;
	std::unordered_map<std::string_view, int> themeCounts;

};


int main() {

	std::string line;
	std::getline(std::cin, line);
	std::istringstream s(line);

	int N;
	s >> N;

	Forum forum;

	for (int i = 0; i < N; ++i) {

		forum.ParseMessage();
	}

	std::cout << forum.GetHottestTheme() << std::endl;

	return 0;
}


