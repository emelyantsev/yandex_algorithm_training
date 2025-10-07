#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

struct Event {

	int t;
	int type;
	int index;

	friend bool operator<(const Event& l, const Event& r) {

		return std::tie(l.t, l.type) < std::tie(r.t, r.type);
	}
};


int main() {

	int n, m;
	std::cin >> n >> m;

	std::vector<Event> events;
	events.reserve(2 * n + m);

	for (int i = 0; i < n; ++i) {

		int ai, bi;
		std::cin >> ai >> bi;

		if (ai > bi) {
			std::swap(ai, bi);
		}

		events.push_back({ ai, -1, -1 });
		events.push_back({ bi, 1, -1 });
	}

	for (int i = 0; i < m; ++i) {

		int pi;
		std::cin >> pi;

		events.push_back({ pi, 0, i });
	}

	std::sort(events.begin(), events.end());

	int count = 0;

	std::vector<int> result(m);
	result.reserve(m);

	for (const Event& event : events) {

		if (event.type == -1) {
			++count;
		}
		else if (event.type == 0) {
			result[event.index] = count;
		}
		else {
			--count;
		}

	}

	for (int res : result) {
		std::cout << res << " ";
	}

	std::cout << std::endl;
}