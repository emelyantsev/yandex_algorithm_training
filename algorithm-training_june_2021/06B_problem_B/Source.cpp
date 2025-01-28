#include <iostream>
#include <algorithm>
#include <utility>
#include <cassert>
#include <vector>


template<typename T>
class OrderedArray {

public:

	OrderedArray(std::vector<T>&& elements_) : elements(elements_) {}

	std::pair<int, int> GetElementPosition(T element) {

		auto lowIt = std::lower_bound(elements.begin(), elements.end(), element);

		if (lowIt == elements.end() || *lowIt != element ) {

			return { 0, 0 };
		}

		auto highIt = std::upper_bound(elements.begin(), elements.end(), element );
		--highIt;

		assert(*highIt == element);

		return  { lowIt - elements.begin() + 1,  highIt - elements.begin() + 1 }   ;
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

	OrderedArray<int> arr(std::move(nums));

	int M;
	std::cin >> M;

	for (int i = 0; i < M; ++i) {

		int num;
		std::cin >> num;

		auto res = arr.GetElementPosition(num);
		std::cout << res.first << " " << res.second << std::endl;
	}


}
