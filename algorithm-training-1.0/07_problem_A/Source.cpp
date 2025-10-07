#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

struct Segment {
	int from;
	int to;

	friend bool operator<(const Segment& l, const Segment& r) {
		
		return std::tie(l.from, l.to) < std::tie(r.from, r.to);
 	}

	bool Intersects(const Segment& other) {

		if (from >= other.from && from <= other.to) {
			return true;
		}
		else if (to >= other.from && to <= other.to) {
			return true;
		}
		else if (other.from >= from && other.from <= to) {
			return true;
		}
		else if (other.to >= from && other.to <= to) {
			return true;
		}
		else {
			return false;
		}

	}
};

int main() {


	int N, M;
	std::cin >> N >> M;

	std::vector<Segment> segments(M);

	for (int i = 0; i < M; ++i) {

		std::cin >> segments[i].from >> segments[i].to;
	}


	std::sort(segments.begin(), segments.end());

	std::vector<Segment> parts;
	parts.push_back(segments.front());

	for (int i = 1; i < M; ++i) {

		if (parts.back().Intersects(segments[i])) {

			parts.back().to = std::max(parts.back().to, segments[i].to);
		}
		else {
			parts.push_back(segments[i]);
		}
	}

	int count = 0;

	for (const Segment& parts : parts) {

		count += parts.to - parts.from + 1;
	}

	std::cout << N - count << std::endl;



}