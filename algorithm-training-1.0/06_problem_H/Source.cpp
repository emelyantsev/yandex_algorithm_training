#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


int get_count(const std::vector<int>& l, int len) {

	if (len == 0) {
		return INT_MAX;
	}

	int res = 0;

	for (const int li : l) {
		res += li / len;
	}

	return res;
}

int main() {

	int N, K;
	std::cin >> N >> K;

	std::vector<int> l(N);


	for (int i = 0; i < N; ++i) {

		std::cin >> l[i];
	}

	int min = 0;
	int max = *std::max_element( l.begin(), l.end() );


	while (true) {

		int mid = min + (max - min) / 2;

		int count = get_count(l, mid);

		if (count < K) {

			max = mid - 1;
		}
		else {

			if ( get_count(l, mid + 1) < K ) {
				std::cout << mid << std::endl;
				break;
			}
			else {
				min = mid + 1;
			}
		}
	}



	return 0;
}