#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>


int get_median(const std::vector<int>& l, const std::vector<int>& r) {

	if (l.front() >= r.back()) {
		return r.back();
	}
	else if (r.front() >= l.back()) {
		return l.back();
	}


	const int n = l.size();

	int min = 0;
	int max = n - 1;

	while (true) {

		int mid = min + (max - min) / 2;

		int min_pos = std::lower_bound(r.begin(), r.end(), l[mid]) - r.begin() + mid;
		int max_pos = std::upper_bound(r.begin(), r.end(), l[mid]) - r.begin() + mid;

		if (n - 1 >= min_pos && n - 1 <= max_pos) {
			return l[mid];
		}
		else if (n - 1 < min_pos) {
			max = mid - 1;
		}
		else if (n - 1 > max_pos) {
			min = mid + 1;
		}

		if (min > max) {
			break;
		}
	}


	min = 0;
	max = n - 1;

	while (true) {

		int mid = min + (max - min) / 2;

		int min_pos = std::lower_bound(l.begin(), l.end(), r[mid]) - l.begin() + mid;
		int max_pos = std::upper_bound(l.begin(), l.end(), r[mid]) - l.begin() + mid;

		if (n - 1 >= min_pos && n - 1 <= max_pos) {
			return r[mid];
		}
		else if (n - 1 < min_pos) {
			max = mid - 1;
		}
		else if (n - 1 > max_pos) {
			min = mid + 1;
		}

		if (min > max) {
			assert(false);
		}
	}

	assert(false);
	return -1;
}


int main() {

	int N, L;

	std::cin >> N >> L;

	std::vector< std::vector<int> > s( N, std::vector<int>(L) );

	for (int i = 0; i < N; ++i) {

		for (int j = 0; j < L; ++j) {

			std::cin >> s[i][j];

		}
	}

	for (int i = 0; i < N - 1; ++i) {

		for (int j = i + 1; j < N; ++j) {

			std::cout << get_median(s[i], s[j]) << std::endl;
		}

	}

	return 0;
}