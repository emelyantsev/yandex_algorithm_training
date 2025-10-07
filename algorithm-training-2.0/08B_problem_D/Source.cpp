#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

class Graph {

public:

	Graph(const int n) : v(n) {}

	void AddPair(int p1, int p2) {

		v[p1].push_back(p2);
		v[p2].push_back(p1);
	}

	int GetMaxLength() {

		h.resize(v.size(), -1);
		fill(0, -1);

		return best_ans;
	}

	void fill(int p, int from) {


		for (int pi : v[p]) {

			if (from != pi) {
				fill(pi, p);
			}
		}

		int max_len = 0;

		std::vector<int> lens;

		for (int pi : v[p]) {

			if (from != pi) {
				max_len = std::max(max_len, h[pi]);
				lens.push_back(h[pi]);
			}
		}

		std::sort( lens.begin(), lens.end() );

		int ans = 0;

		if (lens.size() == 0) {

			ans = 1;
		}
		else if (lens.size() == 1) {
			ans = 1 + lens[0];
		}
		else {

			ans = 1 + lens[lens.size() - 1] + lens[lens.size() - 2];
		} 

		best_ans = std::max(best_ans, ans);

		h[p] = 1 + max_len;
	}

private:

	int best_ans = 0;

	std::vector<int> h;
	std::vector < std::vector<int>> v;

};


int main() {

	int N;
	std::cin >> N;

	Graph g(N);

	for (int i = 0; i < N-1; ++i) {

		int from, to;
		std::cin >> from >> to;
		--from, --to;
		g.AddPair(from, to);
	}

	std::cout << g.GetMaxLength() << std::endl;

}