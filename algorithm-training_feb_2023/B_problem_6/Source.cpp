#include <iostream>
#include <map>


int main() {

	int M;
	std::cin >> M;

	int N;
	std::cin >> N;

	std::map<int, int> segments;

	for (int i = 0; i < N; ++i) {

		int a, b;
		std::cin >> a >> b;
		auto last = segments.upper_bound(b);
		auto first = segments.lower_bound(a);

		if (first != segments.begin() && std::prev(first)->second >= a) {
			--first;
		}

		segments.erase(first, last);
		segments[a] = b;
	}

	std::cout << segments.size() << std::endl;

	return 0;
}