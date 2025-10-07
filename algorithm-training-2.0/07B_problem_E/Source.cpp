#include <iostream>
#include <numbers>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_set>
#include <iomanip>

using namespace std::numbers;

struct PolarRect {

	double r1;
	double r2;
	double f1;
	double f2;

	double GetArea() const {

		assert(f1 != f2);

		if (f1 < f2) {
			return (f2 - f1) * (r2 * r2 - r1 * r1) / 2;
		}
		else {
			return pi * (r2 * r2 - r1 * r1) - (f1 - f2) * (r2 * r2 - r1 * r1) / 2;
		}
	}

};

struct Item {

	double fi;
	int type;
	int id;

	friend bool operator<(const Item& l, const Item& r) {

		return std::tie(l.fi, l.type, l.id) < std::tie(r.fi, r.type, r.id);
	}
};


int main() {


	int N;
	std::cin >> N;

	std::vector<Item> items;
	items.reserve(2 * N);

	std::vector<double> R1, R2;
	R1.reserve(N);
	R2.reserve(N);

	for (int i = 0; i < N; ++i) {

		double r1, r2, f1, f2;
		std::cin >> r1 >> r2 >> f1 >> f2;

		R1.push_back(r1);
		R2.push_back(r2);

		items.push_back({ f2, -1, i } );
		items.push_back({ f1, 1, i });
	}

	const auto min_it = std::min_element(R2.begin(), R2.end());
	const auto max_it = std::max_element(R1.begin(), R1.end());

	double r2 = *min_it;
	double r1 = *max_it;

	if (r2 <= r1) {
		std::cout << 0. << std::endl;
		return 0;
	}
	
	std::sort(items.begin(), items.end());


	std::vector<PolarRect> ans;
	std::unordered_set<int> ids;

	double start = -1.;

	for (int i = 0; i < 2 * items.size(); ++i) {

		const Item& item = items[i % items.size()];

		if (item.type == 1) {

			ids.insert(item.id);

			if (ids.size() == N) {
				start = item.fi;
			}

		}
		else {

			if (ids.size() == N) {


				double end = item.fi;

				if (ans.empty() || ans.front().f1 != start) {
					ans.push_back({ r1, r2, start, end });
				}
				else {

					break;
				}
			}

			ids.erase(item.id);
		}
	}

	double res = 0.;

	for (const PolarRect& rect : ans) {

		res += rect.GetArea();
	}

	std::cout << std::setprecision(9) << res << std::endl;

}