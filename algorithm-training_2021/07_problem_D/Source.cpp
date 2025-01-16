#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cassert>
#include <unordered_set>

struct Item {

	int time;
	int id;

	friend bool operator<(const Item& l, const Item& r) {

		return std::tie(l.time, l.id) < std::tie(r.time, r.id);
	}
};

struct Segment {
	int from;
	int to;
};

int main() {

	int N;
	std::cin >> N;

	std::vector<Item> in, out;
	in.reserve(N);
	out.reserve(N);

	std::vector<Segment> segments;
	segments.reserve(N);

	for (int i = 0; i < N; ++i) {

		int from, to;
		std::cin >> from >> to;
		assert(to > from);

		segments.push_back({ from, to });

		if (to - from < 5) {
			continue;
		}

		in.push_back({ from, i });
		out.push_back({ to, i });

	}

	assert(in.size() == out.size());

	if (in.size() == 0) {
		std::cout << "0 1 6" << std::endl;
		return 0;
	}


	int best_count = 0;
	int t1 = -1;
	int t2 = -1;

	std::sort(in.begin(), in.end());
	std::sort(out.begin(), out.end());

	std::unordered_set<int> s1;

	int l = 0;
	int r = 0;

	while (l < in.size()) {

		s1.insert(in[l].id);

		int i = l + 1;

		while (i < in.size() && in[i].time == in[l].time) {

			s1.insert(in[i].id);
			++i;
		}


		while (r < out.size() && out[r].time < in[l].time + 5) {

			assert(s1.count(out[r].id) == 1);
			s1.erase(out[r].id);
			++r;
		}

		std::unordered_set<int> s2;

		if (s1.size() + s2.size() > best_count) {

			best_count = s1.size() + s2.size();
			t1 = in[l].time;
			t2 = t1 + 5;
		}

		int i1 = i;
		int j1 = r;

		while (i1 < in.size() && in[i1].time <= in[l].time + 5) {

			s2.insert(in[i1].id);
			++i1;
		}

		while (j1 < out.size() && out[j1].time < in[l].time + 10) {
			s2.erase(out[j1].id);
			++j1;
		}

		if (s1.size() + s2.size() > best_count) {

			best_count = s1.size() + s2.size();
			t1 = in[l].time;
			t2 = t1 + 5;
		}

		s2.clear();

		int p = i;
		int q = r;


		while (p < in.size()) {

			s2.insert(in[p].id);

			int j = p + 1;

			while (j < in.size() && in[j].time == in[p].time) {

				s2.insert(in[j].id);
				++j;
			}


			while (q < out.size() && out[q].time < in[p].time + 5) {

				//	assert(s2.count(out[q].id) == 1);
				s2.erase(out[q].id);
				++q;
			}

			if (in[p].time >= in[l].time + 5) {


				if (s1.size() + s2.size() > best_count) {

					best_count = s1.size() + s2.size();
					t1 = in[l].time;
					t2 = in[p].time;
				}

			}

			p = j;

		}

		l = i;

	}

	//	int count = 0;

		//assert(t1 + 5 <= t2);

		//for (const Segment& segment : segments) {

		//	if ( (segment.from <= t1 && segment.to >= t1 + 5) || (segment.from <= t2 && segment.to >= t2 + 5) ) {
		//		++count;
		//	}
		//}

		//assert(count == best_count);

	std::cout << best_count << " " << t1 << " " << t2 << std::endl;

	return 0;
}