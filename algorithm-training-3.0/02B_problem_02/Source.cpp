#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

int getAns(const std::string& s, int k, char c) {

	int l = 0;
	int r = 0;

	int best_ans = 0;

	int count = 0;

	while (true) {

		assert(count <= k);

		r = std::max(l, r);

		while ( r < s.size() ) {

			if (s[r] == c) {
				++r;
			}
			else {

				if (count == k) {
					break;
				}
				else {
					++count;
					++r;
				}
			}
		}

		int len = r - l;

		best_ans = std::max(best_ans, len);

		if ( r == s.size() ) {
			break;
		}

		if ( s[l] != c ) {

			--count;
		}

		++l;
	}

	return best_ans;
}


int main() {


	int k;
	std::cin >> k;

	std::string s;
	std::cin >> s;

	int best_ans = 0;

	for (char c = 'a'; c <= 'z'; ++c) {


		int ans = getAns(s, k, c);
		best_ans = std::max(best_ans, ans);
	}

	std::cout << best_ans << std::endl;

	return 0;
}