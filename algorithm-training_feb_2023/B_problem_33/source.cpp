#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_set>
#include <queue>

class Graph {

    public:

        Graph(int n) : N(n), edges(n) {}

        void AddAdge(int v1, int v2) {

            edges[v1].push_back(v2);
            edges[v2].push_back(v1);
        }

        bool IsBipartee() {

            std::vector<int> colors(N, -1);

            std::unordered_set<int> vertices;

            for (int i = 0; i < N; ++i) {
                vertices.insert(i);
            }


            while ( !vertices.empty() ) {


                int start = *vertices.begin();

                colors[start] = 0;

                std::queue<int> q;
                q.push(start);
                vertices.erase(start);

                while ( !q.empty() ) {

                    int curr = q.front();
                    q.pop();

                    for (int to : edges[curr] ) {

                        if (colors[to] == -1) {

                            colors[to] = (colors[curr] + 1) % 2;
                            q.push(to);
                            vertices.erase(to);
                        }
                        else if (colors[to] == colors[curr]) {
                            return false;
                        }

                    }

                }

            }

            return true;
        }

    private:

        int N;
        std::vector<std::vector<int> > edges;

};


int main() {

    int N, M;
    std::cin >> N >> M;

    Graph g(N);

    for (int i = 0; i < M; ++i) {


        int v1, v2;
        std::cin >> v1 >> v2;
        g.AddAdge(--v1, --v2);
    }

    std::cout << ( g.IsBipartee() ? "YES" : "NO" ) << std::endl;


    return 0;
}