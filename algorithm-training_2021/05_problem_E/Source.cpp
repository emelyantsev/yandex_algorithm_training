#include <iostream>
#include <vector>
#include <unordered_map>

int main() {

	int N, K;
	std::cin >> N >> K;

	std::vector<int> nums(N);

	for (int i = 0; i < N; ++i) {

		std::cin >> nums[i];
	}

	int l = 0;
	int r = 1;

	std::unordered_map<int, int> counts;
	counts[nums[0]] = 1;

	int la = 0 ;
	int ra = N - 1;

	while (true) {

		while (counts.size() < K && r < N) {

			counts[nums[r]] += 1;
			++r;
		}

		if (counts.size() == K) {

			int curr_best_len = ra - la + 1;
			int curr_len = r - l;

			if (curr_len < curr_best_len) {
				la = l;
				ra = r-1;
			}
		}

		while (counts.size() == K) {

			counts[nums[l]] -= 1;
			
			if (counts[nums[l]] == 0) {
				counts.erase(nums[l]);
			}

			++l;

			if (counts.size() == K) {

				int curr_best_len = ra - la + 1;
				int curr_len = r - l;

				if (curr_len < curr_best_len) {
					la = l;
					ra = r-1;
				}
			}

		}

		if (r == N) {
			break;
		}
	}

	std::cout << la + 1 << " " << ra + 1 << std::endl;

}