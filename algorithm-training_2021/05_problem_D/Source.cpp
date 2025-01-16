#include <iostream>
#include <vector>

int main() {

	int n, r;
	std::cin >> n >> r;

	std::vector<int> d(n);

	for (int i = 0; i < n; ++i) {

		std::cin >> d[i];
	}

	int left = 0;
	int right = 1;

	long long count = 0;

	while (true) {

		while (right < n && d[right] - d[left] <= r) {

			++right;
		}

		if (right == n) {
			break;
		}
		else {
			count += n - right;
		}

		++left;
	}

	std::cout << count << std::endl;

}