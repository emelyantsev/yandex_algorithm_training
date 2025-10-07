#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_set>
#include <cassert>

class Solver {

public:

	struct Event {

		int time;
		int type;
		int id;

		friend bool operator<(const Event& l, const Event& r) {

			return std::tie(l.time, l.type, l.id) < std::tie(r.time, r.type, r.id);
		}
	};

	void Process() {

		std::cin >> n;
		events.reserve(2 * n);

		for (int i = 0; i < n; ++i) {

			int from, to;
			std::cin >> from >> to;

			if (from == to) {
				std::cout << "Wrong Answer" << std::endl;
				return;
			}

			events.push_back({ from + 1, -1, i });
			events.push_back({ to, 1, i });

		}

		std::sort(events.begin(), events.end());

		if (events.front().time != 1 || events.back().time != 10000) {
			std::cout << "Wrong Answer" << std::endl;
			return;
		}

		int empty_time = 0;
		std::vector<int> times(n, 0);
		std::unordered_set<int> ids;

		ids.insert(events[0].id);

		for (int i = 1; i < events.size(); ++i) {

			if (events[i].type == -1) {

				if (ids.size() == 0) {

					assert(events[i - 1].type == 1);
					int time_diff = events[i].time - events[i - 1].time;

					if (time_diff > 1) {
						std::cout << "Wrong Answer" << std::endl;
						return;
					}

				}
				else if (ids.size() == 1) {

					const Event& prev_event = events[i - 1];
					int id = *ids.begin();

					if (prev_event.type == 1) {

						int time_diff = events[i].time - prev_event.time;
						times[id] += time_diff;
					}
					else {

						int time_diff = events[i].time - prev_event.time;
						times[id] += time_diff;

					}
				}

				ids.insert(events[i].id);

			}
			else {

				assert(ids.size() > 0);

				if (ids.size() == 1) {

					int id = *ids.begin();
					assert(id == events[i].id);

					const Event& prev_event = events[i - 1];

					if (prev_event.type == 1) {

						int time_diff = events[i].time - prev_event.time;
						times[id] += time_diff;
					}
					else {
						assert(prev_event.type == -1);
						int time_diff = events[i].time - prev_event.time + 1;
						times[id] += time_diff;
					}
				}

				ids.erase(events[i].id);
			}

		}

		for (int t : times) {
			if (t == 0) {
				std::cout << "Wrong Answer" << std::endl;
				return;
			}
		}

		std::cout << "Accepted" << std::endl;
	}

private:

	int n;

	std::vector<Event> events;


};


int main() {


	int K;
	std::cin >> K;


	for (int i = 0; i < K; ++i) {

		Solver().Process();
	}


	return 0;
}