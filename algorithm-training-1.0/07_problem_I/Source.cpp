#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <cassert>
#include <string>

struct Time {

	Time(const std::string& s) {

		assert(s.size() == 5);
		h = std::stoi(s.substr(0, 2));
		m = std::stoi(s.substr(3, 2));
	}

	int h;
	int m;

	friend bool operator<(const Time& l, const Time& r) {

		return std::tie(l.h, l.m) < std::tie(r.h, r.m);
	}
};

struct Event {

	Time t;
	int type;
	int city;

	friend bool operator<(const Event& l, const Event& r) {

		return std::tie(l.t, l.type) < std::tie(r.t, r.type);
	}
};


int main() {


	int N, M;
	std::cin >> N >> M;


	std::vector<Event> events_day1;
	events_day1.reserve(2 * M);
	std::vector<Event> events;
	events.reserve(2 * M);

	std::vector<int> counts(N, 0);


	for (int i = 0; i < M; ++i) {

		int from, to;
		std::string s1, s2;
		std::cin >> from >> s1 >> to >> s2;

		--from; --to;

		Time t1(s1);
		Time t2(s2);

		if (t1 < t2) {
			events_day1.push_back({ t2, -1, to });
			events.push_back({ t2, -1, to });

			events_day1.push_back({ t1, 1, from });
			events.push_back({ t1, 1, from });
		}
		else {

			events.push_back({ t2, -1, to });
			events_day1.push_back({ t1, 1, from });
			events.push_back({ t1, 1, from });
		}

		--counts[from];
		++counts[to];

	}

	for (int count : counts) {
		if (count != 0) {
			std::cout << -1 << std::endl;
			return 0;
		}

	}

	std::sort(events_day1.begin(), events_day1.end());
	std::sort(events.begin(), events.end());


	std::vector<int> curr_counts(N, 0);

	int needed = 0;

	for (const Event& event : events_day1) {

		if (event.type == -1) {
			++curr_counts[event.city];
		}
		else {

			if (curr_counts[event.city] == 0) {
				++needed;
			}
			else {
				--curr_counts[event.city];
			}
		}
	}

	int prev_needed = needed;

	while (true) {

		for (const Event& event : events) {

			if (event.type == -1) {
				++curr_counts[event.city];
			}
			else {

				if (curr_counts[event.city] == 0) {
					++needed;
				}
				else {
					--curr_counts[event.city];
				}
			}
		}

		if (needed == prev_needed) {
			break;
		}
		else {
			prev_needed = needed;
		}

	}

	std::cout << needed << std::endl;




	return 0;
}