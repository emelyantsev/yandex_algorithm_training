#include <iostream>
#include <string>
#include <array>

bool is_valid(const std::array<int, 26>& counts, int k) {

	for (int c : counts) {

		if (c > k) {
			return false;
		}
	}

	return true;
}


int main() {


	int n, k;
	std::cin >> n >> k;

	std::string s;
	std::cin >> s;


	int l = 0;
	int r = 0;

	std::array<int, 26> counts{};

	int la = -1;
	int best_len = 0;

	while (true) {

		if (is_valid(counts, k)) {

			int len = r - l;

			if (len > best_len) {
				best_len = len;
				la = l;
			}

			if (r == n) {
				break;
			}

			counts[s[r] - 'a'] += 1;

			++r;
		}
		else {
			counts[s[l] - 'a'] -= 1;
			++l;
		}
	}
	
	std::cout << best_len << " " << la + 1 << std::endl;

}