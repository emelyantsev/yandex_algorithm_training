#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <cassert>
#include <string>
#include <set>

struct Item {

	int height;
	int type;
	int area;
	int id;

	friend bool operator<(const Item& l, const Item& r) {

		return std::tie(l.height, l.type, l.area, l.id) < std::tie(r.height, r.type, r.area, r.id);
	}

};

int main() {

	int N;
	int W, L;

	std::cin >> N >> W >> L;

	std::vector<Item> items;

	for (int i = 0; i < N; ++i) {

		int x1, y1, z1;
		int x2, y2, z2;

		std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

		int dx = x2 - x1;
		int dy = y2 - y1;

		items.push_back({ z1, 1, dx * dy, i + 1 });
		items.push_back({ z2, -1, dx * dy, i + 1 });
	}

	std::sort(items.begin(), items.end());

	int S = W * L;

	int best_count = N + 1;

	std::set<int> ids;

	int curr_area = 0;

	for (const Item& item : items) {

		if (item.type == -1) {
			ids.erase(item.id);
			curr_area -= item.area;
		}
		else {
			ids.insert(item.id);
			curr_area += item.area;

			if (curr_area == S) {

				best_count = std::min(best_count, (int)ids.size());
			}
		}

	}

	if (best_count == N + 1) {
		std::cout << "NO" << std::endl;
		return 0;
	}

	ids.clear();
	curr_area = 0;

	for (const Item& item : items) {

		if (item.type == -1) {
			ids.erase(item.id);
			curr_area -= item.area;
		}
		else {
			ids.insert(item.id);
			curr_area += item.area;

			if (curr_area == S && ids.size() == best_count) {

				break;
			}
		}

	}

	std::cout << "YES" << std::endl;
	std::cout << ids.size() << std::endl;

	for (int id : ids) {
		std::cout << id << std::endl;
	}



	return 0;
}