#include <iostream>
#include <vector>
#include <cassert>

int main() {

	int N, K;
	std::cin >> N >> K;

	std::vector<int> nums;
	nums.reserve(N);

	for (int i = 0; i < N; ++i) {

		int num;
		std::cin >> num;
		nums.push_back(num);
	}

	int count = 0;

	int l = 0;
	int r = 0;

	int curr_sum = 0;

	while (true) {

		while (curr_sum < K && r < N) {

			curr_sum += nums[r];
			++r;
		}

		if (curr_sum == K) {

			//std::cout << l << " " << r << std::endl;
			++count;
		}



		while (curr_sum >= K) {

			curr_sum -= nums[l];
			++l;

			if (curr_sum == K) {

				//std::cout << l << " " << r << std::endl;
				++count;
			}
		}

		if (r == N) {
			break;
		}

	}

	std::cout << count << std::endl;
}
