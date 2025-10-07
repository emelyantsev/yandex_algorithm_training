#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

int main() {

	int N;
	std::cin >> N;
	std::vector<int> nums1;
	nums1.reserve(N);

	for (int i = 0; i < N; ++i) {

		int num;
		std::cin >> num;
		nums1.push_back(num);
	}

	int M;
	std::cin >> M;
	std::vector<int> nums2;
	nums2.reserve(M);

	for (int i = 0; i < M; ++i) {

		int num;
		std::cin >> num;
		nums2.push_back(num);
	}


	int best_diff = INT_MAX;
	int num1, num2;


	int p1 = 0;
	int p2 = 0;

	while (p1 < N && p2 < M) {

		if (nums1[p1] == nums2[p2]) {
			
			num1 = nums1[p1];
			num2 = nums2[p2];
			break;
		}
		else if (nums1[p1] < nums2[p2]) {

			int diff = nums2[p2] - nums1[p1];

			if (diff < best_diff) {
				num1 = nums1[p1];
				num2 = nums2[p2];
				best_diff = diff;
			}

			++p1;
		}
		else {

			int diff = nums1[p1] - nums2[p2];

			if (diff < best_diff) {
				num1 = nums1[p1];
				num2 = nums2[p2];
				best_diff = diff;
			}

			++p2;

		}

	}

	std::cout << num1 << " " << num2 << std::endl;
}