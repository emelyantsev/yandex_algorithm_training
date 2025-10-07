#include <iostream>
#include <vector>
#include <set>
#include <queue>

class Graph {

public:

	Graph(int N) : v(N) {}

	void AddEdge(int from, int to) {
		--from, --to;
		v[from].insert(to);
		v[to].insert(from);
	}

	std::set<int> GetConnectedComponent(int from) {

		std::set<int> result;
		result.insert(from);
		std::queue<int> q;
		q.push(from);

		while (!q.empty()) {

			int top = q.front();
			q.pop();

			for (const int v : v[top]) {

				if (result.count(v) == 0) {
					result.insert(v);
					q.push(v);
				}
			}

		}

		return result;
	}

private:

	std::vector<std::set<int> > v;
};


int main() {

	int N, M;
	std::cin >> N >> M;

	Graph g(N);

	for (int i = 0; i < M; ++i) {

		int from, to;
		std::cin >> from >> to;

		g.AddEdge(from, to);
	}

	auto component = g.GetConnectedComponent(0);

	std::cout << component.size() << std::endl;

	for (int v : component) {
		std::cout << ++v << " ";
	}

	std::cout << std::endl;

}