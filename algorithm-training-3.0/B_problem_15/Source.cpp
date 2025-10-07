#include <iostream>
#include <vector>
#include <stack>


struct Item {
	int val;
	int ind;
};


int main() {


	int N;
	std::cin >> N;

	std::vector<int> ans(N, -1);

	std::stack<Item> items;

	int a;
	std::cin >> a;
	items.push( { a, 0 } );
	
	for (int i = 1; i < N; ++i) {

		std::cin >> a;

		while (!items.empty() && a < items.top().val) {

			ans[items.top().ind] = i;
			items.pop();
		}

		items.push({ a, i });
	}

	for (int ans_ : ans) {
		std::cout << ans_ << " ";
	}

	std::cout << std::endl;




	return 0;
}