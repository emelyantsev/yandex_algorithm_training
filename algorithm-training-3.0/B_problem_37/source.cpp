#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Graph {

    public:

        Graph(int n) : N(n), edges(n) {}

        void AddEdge(int v1, int v2) {

            edges[v1].push_back(v2);
        }

        std::vector<int> GetPath(int from, int to) {

            std::vector<int> parent(N, -1);
            parent[from] = from;

            std::queue<int> q;
            q.push(from);

            std::vector<int> path;

            while (!q.empty()) {

                int curr = q.front();
                q.pop();

                if (curr == to) {
                    
                    path.push_back(curr);

                    while (parent[curr] != curr) {

                        curr = parent[curr];
                        path.push_back(curr);
                    }
                    
                    return path;
                }

                for (int ci : edges[curr] ) {

                    if (parent[ci] == -1) {

                        parent[ci] = curr;
                        q.push(ci);
                    }

                }

            }


            return {};
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

    auto path = g.GetPath(--from, --to);

    if (path.size() == 0) {
        std::cout << -1 << std::endl;
    }
    else {

        if (path.size() == 1) {
            std::cout << 0 << std::endl;
        }
        else {
            std::cout << path.size() - 1 << std::endl;

            for (int v : path) {
                std::cout << ( v+1 ) << " " ;
            }
            std::cout << std::endl;
        }

    }


    return 0;
}