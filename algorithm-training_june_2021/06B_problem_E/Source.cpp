#include <iostream>
#include <vector>
#include <algorithm>


bool is_possible(const std::vector<int>& nums, int k, int len) {

	int start = nums.front();
	--k;

	for (int i = 1; i < nums.size(); ++i) {

		if (nums[i] > start + len) {

			if (k == 0) {
				return false;
			}

			start = nums[i];
			--k;
		}
	}

	return true;
}



int main() {

	int n, k;
	std::cin >> n >> k;

	std::vector<int> x(n);

	for (int i = 0; i < n; ++i) {

		std::cin >> x[i];
	}

	std::sort( x.begin(), x.end() );

	int l = 0;
	int r = x.back() - x.front();


	while (true) {

		int mid = l + (r - l) / 2;


		if (is_possible(x, k, mid)) {

			if (mid == 0 || !is_possible(x, k, mid - 1)) {

				std::cout << mid << std::endl;
				break;
			}
			else {

				r = mid - 1;
			}

		}
		else {

			l = mid + 1;
		}
	}

	return 0;
}