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

    int N, M;
    std::cin >> N >> M;


    Graph g(N);

    for (int i = 0; i < M; ++i) {

        int count;
        std::cin >> count ;
        std::vector<int> line(count);

        for (int j = 0; j < count; ++j) {

            std::cin >> line[j];
            --line[j];
        }

        for (int p = 0; p < count; ++p) {

            for (int q = 0; q < count; ++q) {

                if ( p != q) {

                    g.AddEdge(line[p], line[q]);
                }
            }
        }
    }

    int from, to;
    std::cin >> from >> to;
    --from; --to;

    int ans = g.GetLength(from, to);

    if (ans > 0) {
        std::cout << (ans - 1 ) << std::endl;
    }
    else {
        std::cout << ans << std::endl;
    }


    return 0;
}