#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_set>
#include <stack>

class Graph {

    public:

        Graph(int n) : N(n), edges(n) {}

        void AddEdge(int v1, int v2) {

            edges[v1].push_back(v2);
        }

        std::vector<int> GetCycle() {

            std::vector<int> parents(N, -1);

            std::unordered_set<int> vertices;

            for (int i = 0; i < N; ++i) {
                vertices.insert(i);
            }


            while ( !vertices.empty() ) {


                int start = *vertices.begin();

                parents[start] = start;

                std::stack<int> s;
                s.push(start);
                vertices.erase(start);

                while ( !s.empty() ) {

                    int curr = s.top();
                    s.pop();

                    for (int to : edges[curr] ) {

                        if (parents[to] == -1) {

                            parents[to] = curr;
                            s.push(to);
                            vertices.erase(to);
                        }
                        else if (parents[curr] != to) {
                            
                            std::vector<int> ans;
                            ans.push_back(to);
                            ans.push_back(curr);
                            
                            while ( curr != parents[ans.front()]) {
                                curr = parents[curr];
                                ans.push_back(curr);
                            }

                            return ans;

                        }

                    }

                }

            }

            return {};
        }

    private:

        int N;
        std::vector<std::vector<int> > edges;

};


int main() {

    int N;
    std::cin >> N ;

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

    std::vector<int> cycle = g.GetCycle();

    std::cout << ( cycle.size() != 0 ? "YES" : "NO" ) << std::endl;


    if ( cycle.size() > 0 ) {

        std::cout << cycle.size() << std::endl;
    }

    

    for (int v : cycle) {
        std::cout << (v + 1 ) << " ";
    }
    std::cout << std::endl;

    return 0;
}