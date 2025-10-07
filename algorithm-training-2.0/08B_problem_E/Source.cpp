#include <iostream>
#include <string>
#include <vector>

class Solver {
public:
	Solver(const std::string& path_) : path(path_) {}

	std::vector< std::string > GetAnswer() {

		std::vector< std::string > ans;
		std::string curr_code;

		for (char c : path) {
			if (c == 'D') {
				curr_code.push_back('0');
			}
			else {

				ans.push_back(curr_code);

				while (true) {
					if (curr_code.back() == '1') {
						curr_code.pop_back();
					}
					else {
						curr_code.back() = '1';
						break;
					}
				}
			}
		}

		ans.push_back(curr_code);

		return ans;

	}

private:

	std::string path;
};

int main() {

	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i) {

		std::string path;
		std::cin >> path;
		Solver solver(path);

		auto ans = solver.GetAnswer();

		std::cout << ans.size() << std::endl;

		for (const std::string& code : ans) {
			std::cout << code << std::endl;
		}

	}


}