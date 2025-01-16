#include <string>
#include <iostream>
#include <unordered_set>

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& set)
{
	out << set.size() << std::endl;

	for (const T& item : set) {
		out << item << std::endl;
	}

	return out;
}


int main() {


	int N;
	std::cin >> N;

	std::unordered_set<std::string> all, any;

	int M;
	std::cin >> M;

	for (int i = 0; i < M; ++i) {

		std::string lang;
		std::cin >> lang;
		all.insert(lang);
		any.insert(lang);
	}


	for (int i = 0; i < N - 1; ++i) {

		int mi;
		std::cin >> mi;
		
		std::unordered_set<std::string> new_all;

		for (int j = 0; j < mi; ++j) {

			std::string lang;
			std::cin >> lang;

			any.insert(lang);
		
			if (all.count(lang) == 1) {
				new_all.insert(lang);
			}

		}

		all = std::move(new_all);
	}


	std::cout << all << any;
}