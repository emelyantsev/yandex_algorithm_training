#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

struct Item {
	int val;
	int id;

	friend bool operator<(const Item& l, const Item& r) {
		return std::tie(l.val, l.id) < std::tie(r.val, r.id);
	}
};

int main() {

	int N;
	std::cin >> N;

	std::vector<int> nums(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> nums[i];
	}

	//std::vector<int> nums{ 2,3,2,5,3,1,0,5 };

	std::sort(nums.begin(), nums.end());
	nums.erase( std::unique(nums.begin(), nums.end() ), nums.end() );

	int K;
	std::cin >> K;

	std::vector<int> ans(K);

	std::vector<Item> vals(K);
	for (int i = 0; i < K; ++i) {
		std::cin >> vals[i].val ;
		vals[i].id = i;
	}

	std::sort(vals.begin(), vals.end());

	int ind = 0;

	for (const Item& item : vals) {


		while (ind < nums.size() && nums[ind] < item.val) {
			++ind;
		}

		ans[item.id] = ind;
	}

	for (int a : ans) {
		std::cout << a << std::endl;
	}

	return 0;
}