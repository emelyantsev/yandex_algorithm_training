#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

template<typename T>
class OrderedArray {

public:

	OrderedArray(std::vector<T>&& elements_) : elements(elements_) {
		std::sort(elements.begin(), elements.end());
	}

	int GetElementsCount(T from, T to) {

		auto highIt = std::upper_bound( elements.begin(), elements.end(), to );
		auto lowIt = std::lower_bound(elements.begin(), elements.end(), from);

		return highIt - lowIt;
	}

private:


	std::vector<T> elements;

};

int main() {

	
	int N;
	std::cin >> N;

	std::vector<int> nums(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> nums[i];
	}

	OrderedArray<int> arr(std::move(nums) );


	int K;
	std::cin >> K;

	for (int i = 0; i < K; ++i) {

		int from, to;
		std::cin >> from >> to;
		std::cout << arr.GetElementsCount(from, to) << " ";
	}

	std::cout << std::endl;

	return 0;
}