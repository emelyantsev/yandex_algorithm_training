#include <vector>
#include <iostream>

class SumArray {

public:

	SumArray(int n) {
		a.reserve(n);
		partSums.reserve(n);
	}

	void AddNumber(long long num) {

		a.push_back(num);
		partSums.push_back(partSums.size() == 0 ? num : partSums.back() + num);

	}

	long long GetSum(int from, int to) {
		--from;
		--to;

		return partSums[to] - (from == 0 ? 0 : partSums[from - 1]);

	}

private:


	std::vector<long long> a;
	std::vector<long long> partSums;
};


int main() {

	int n, q;
	std::cin >> n >> q;

	SumArray arr(n);

	for (int i = 0; i < n; ++i) {

		long long a;
		std::cin >> a;
		arr.AddNumber(a);
	}

	for (int i = 0; i < q; ++i) {

		int l, r;
		std::cin >> l >> r;
		std::cout << arr.GetSum(l, r) << std::endl;

	}

	return 0;
}