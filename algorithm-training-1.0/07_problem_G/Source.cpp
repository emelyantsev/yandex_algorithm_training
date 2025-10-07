#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

class Helper {

public:

	Helper(int t_, int z_, int y_ ) : t(t_), z(z_), y(y_), cnt(0), curr_time(0) {}

	int getNext() {

		if (cnt != 0 && cnt % z == 0) {
			
			curr_time += y + t;
			++cnt;
			return curr_time;
		}
		else {
			curr_time += t;
			++cnt;
			return curr_time;
		}
	}

	int getCount() const { return cnt; }

private:

	int t;
	int z;
	int y;
	int cnt;
	int curr_time;

};

struct HelperItem {

	HelperItem(int time_, int id_) : time(time_), id(id_) {}

	int time;
	int id;

	friend bool operator<(const HelperItem& l, const HelperItem& r) {

		
		if (l.time > r.time) {
			return true;
		}
		else if (l.time == r.time) {
			return l.id > r.id;
		}
		else {
			return false;
		}

	}
};


int main() {

	int M, N;
	std::cin >> M >> N;

	std::vector<Helper> helpers;
	helpers.reserve(N);

	for (int i = 0; i < N; ++i) {

		int t, z, y;
		std::cin >> t >> z >> y;
		helpers.emplace_back(t, z, y);
	}

	std::vector<HelperItem> items;

	for (int i = 0; i < N; ++i) {

		int t = helpers[i].getNext();
		items.emplace_back(t, i);
		std::push_heap(items.begin(), items.end());
	}

	int count = 0;
	int ans = 0;


	while (count != M) {

		HelperItem item = items.front();

		std::pop_heap(items.begin(), items.end());
		items.pop_back();

		int t = helpers[item.id].getNext();
		items.emplace_back(t, item.id);
		std::push_heap(items.begin(), items.end());

		++count;

		if (count == M) {
			ans = item.time;
			break;
		}
	}

	std::cout << ans << std::endl;

	for (const Helper& helper : helpers) {

		std::cout << helper.getCount() - 1 << " ";
	}

	std::cout << std::endl;

	return 0;
}