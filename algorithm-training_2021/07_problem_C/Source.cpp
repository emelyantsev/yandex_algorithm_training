#include <iostream>
#include <algorithm>
#include <vector>

struct Item {

	int val;
	int index;

	friend bool operator<(const Item& l, const Item& r) {

		return l.val < r.val;
	}
};


int main() {

	int N, D;
	std::cin >> N >> D;

	std::vector<Item> x(N);

	for (int i = 0; i < N; ++i) {

		std::cin >> x[i].val ;
		x[i].index = i;
	}

	std::sort(x.begin(), x.end());

	int l = 0;
	int r = 1;

	int count = 0;

	while (true) {

		while (r < x.size() && x[r].val - x[l].val <= D) {
			++r;
		}

		int curr_count = r - l;
		count = std::max(count, curr_count);


		if (r == x.size()) {
			break;
		}

		++l;
	}

	std::cout << count << std::endl;

	std::vector<int> answers(N);

	for (int i = 0; i < N; ++i) {

		int curr_var = i % count + 1;
		answers[x[i].index] = curr_var;

		
	 }

	for (int ans : answers) {
		std::cout << ans << " ";
	}


	std::cout << std::endl;

}
