#include <iostream>
#include <vector>
#include <queue>

class Graph {

    public:

        Graph(int n) : N(n), edges(n) {}

        void AddEdge(int v1, int v2) {

            edges[v1].push_back(v2);
        }

        int GetLength(int from, int to) {

            std::vector<int> depth(N, -1);
            depth[from] = 0;

            std::queue<int> q;
            q.push(from);

            while (!q.empty()) {

                int curr = q.front();
                q.pop();

                if (curr == to) {
                    return depth[curr];
                }

                for (int ci : edges[curr] ) {

                    if (depth[ci] == -1) {

                        depth[ci] = depth[curr] + 1;
                        q.push(ci);
                    }

                }

            }


            return -1;
        }

    private:

    int N;
    std::vector<std::vector<int>> edges;
};

int main() {

    int N;
    std::cin >> N;

    Graph g(N);

    for (int i = 0; i < N; ++i) {

        for (int j = 0; j < N; ++j) {

            int val;
            std::cin >> val;

            if (val == 1) {

                g.AddEdge(i, j);
            }
        }
    }

    int from, to;
    std::cin >> from >> to;

    std::cout << g.GetLength(--from, --to) << std::endl;

    return 0;
}