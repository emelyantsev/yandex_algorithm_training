#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


bool is_good(const std::vector<int>& counts, int R, int C, int diff) {

	int res = 0;

	for (int i = 0; i < counts.size(); ) {

		if (counts[i] <= diff) {
			++res;
			i += C;
		}
		else {
			++i;
		}
	}

	return res >= R;

}


int main() {

	int N, R, C;

	std::cin >> N >> R >> C;

	std::vector<int> h(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> h[i];
	}

	std::sort( h.begin(), h.end() );

	std::vector<int> w;

	for (int i = C - 1; i < N; ++i) {

		w.push_back(h[i] - h[i - C + 1] );
	}

	int min = 0;
	int max = h.back() - h.front();


	while (true) {


		int mid = min + (max - min) / 2;

		if (!is_good(w, R, C, mid)) {
			min = mid + 1;
		}
		else {

			if (mid == 0 || !is_good(w, R, C, mid - 1)) {

				std::cout << mid << std::endl;
				break;
			}
			else {

				max = mid - 1;
			}
		}
	}

	


	return 0;
}

