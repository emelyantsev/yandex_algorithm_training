#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

struct Segment {
	int from;
	int to;

	bool IntersectsWith(const Segment& other) {

		return !(this->from > other.to || this->to < other.from);
	}
};


int main() {

	int M;
	std::cin >> M;
	int N;
	std::cin >> N;

	std::vector<Segment> segments;
	segments.reserve(N);

	std::vector<bool> ans(N, true);

	for (int i = 0; i < N; ++i) {

		Segment seg;
		std::cin >> seg.from >> seg.to;

		for (int j = 0; j < segments.size(); ++j) {

			if (segments[j].IntersectsWith(seg)) {
				ans[j] = false;
			}
		}

		segments.push_back(seg);
	}

	int count = std::count(ans.begin(), ans.end(), true);

	std::cout << count << std::endl;

	return EXIT_SUCCESS;
}