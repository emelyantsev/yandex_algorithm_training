#include <iostream>
#include <string>

int main() {


	int K;
	std::cin >> K;

	std::string s;
	std::cin >> s;

	long long count = 0;

	long long prev_count = 0;

	for (int i = K; i < s.size(); ++i) {

		if (s[i] == s[i - K]) {

			++prev_count;
			count += prev_count;
		}
		else {

			prev_count = 0;
		}
	}

	std::cout << count << std::endl;
}
