#include <iostream>
#include <vector>


template <typename Iterator, typename Value>
bool binary_search(Iterator from, Iterator to, const Value& value) {


	if (from == to) {
		return false;
	}

	int len = to - from;

	if (len == 1) {
		return *from == value;
	}

	int mid = len / 2;

	Value mid_value = *(from + mid);

	if ( mid_value == value) {
		return true;
	}
	else if (value < mid_value) {
		return binary_search(from, from + mid, value);
	}
	else {
		return binary_search(from + mid + 1, to, value);
	}
}


int main() {

	int N, K;

	std::cin >> N >> K;

	std::vector<int> values(N);

	for (int i = 0; i < N; ++i) {

		std::cin >> values[i];
	}

	for (int i = 0; i < K; ++i) {

		int value;
		std::cin >> value;

		std::cout << (binary_search(values.begin(), values.end(), value) == true ? "YES" : "NO") << std::endl;


	}


}


