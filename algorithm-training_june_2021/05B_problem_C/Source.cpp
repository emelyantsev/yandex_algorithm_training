#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

struct Item {

	int val;
	int id;


	friend bool operator<(const Item& l, const Item& r) {

		return std::tie(l.val, l.id) < std::tie(r.val, r.id);
	}
};

int main() {

	int N, M;
	std::cin >> N >> M;

	std::vector<Item> groups;
	groups.reserve(N);

	for (int i = 0; i < N; ++i) {

		int val;
		std::cin >> val;

		groups.push_back({ val, i });
	}

	std::vector<Item> rooms;
	rooms.reserve(M);

	for (int i = 0; i < M; ++i) {
		int val;
		std::cin >> val;
		rooms.push_back({val, i});
	}

	std::sort(groups.begin(), groups.end() );
	std::sort(rooms.begin(), rooms.end());

	int count = 0;

	int g = 0;
	int r = 0;

	std::vector<int> ans(N, 0);

	while (true) {

		while (r < M && rooms[r].val < groups[g].val + 1) {
			++r;
		}

		if (r == M) {
			break;
		}

		ans[groups[g].id] = rooms[r].id + 1;
		++count;
		++g;
		++r;
	}

	std::cout << count << std::endl;

	for (int val : ans) {
		std::cout << val << " ";
	}
	std::cout << std::endl;

	return 0;

}