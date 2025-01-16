#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

struct Event {

	Event(int time_, int type_) : time(time_), type(type_) {}

	int time;
	int type;

	friend bool operator<(const Event& l, const Event& r) {

		return std::tie(l.time, l.type) < std::tie(r.time, r.type);
	}
};

int main() {

	int N;
	std::cin >> N;

	std::vector<Event> events;
	events.reserve(N*2);

	for (int i = 0; i < N; ++i) {

		int hh0, mm0, hh1, mm1;
		std::cin >> hh0 >> mm0 >> hh1 >> mm1;

		int from = hh0 * 60 + mm0;
		int to = hh1 * 60 + mm1;

		if (from < to) {
			events.emplace_back(from, -1);
			events.emplace_back(to, 1);
		}
		else if (from == to) {
			events.emplace_back(0, -1);
			events.emplace_back(1440, 1);
		}
		else {
			events.emplace_back(from, -1);
			events.emplace_back(1440, 1);
			events.emplace_back(0, -1);
			events.emplace_back(to, 1);
		}

	}

	std::sort(events.begin(), events.end());

	int count = 0;
	int full_count_time = 0;

	for (int i = 0; i < events.size(); ++i) {

		if (events[i].type == -1) {

			++count;
		}
		else {

			if (count == N) {

				full_count_time += events[i].time - events[i - 1].time;
			}

			--count;
		}
	}

	std::cout << full_count_time << std::endl;

}