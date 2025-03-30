#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

class Tree {

    public:

        Tree(int N) : edges(N), parent_of(N, -1), counts(N, -1) {}

        void AddEdge(int from, int to) {

            edges[from].push_back(to);
            edges[to].push_back(from);

        }

        std::vector<int> GetSubtreeVerticesCount() {

            getCount(0);
            return counts;
        }

    private:

        void getCount(int i) {

            int res = 0;

            for (int vi : edges[i] ) {

                if (parent_of[i] != vi) {
                    
                    parent_of[vi] = i;
                    getCount(vi);
                    res += counts[vi];
                }
            }

            res += 1;
            counts[i] = res;
        }

        std::vector<std::vector<int>> edges;
        std::vector<int> parent_of;
        std::vector<int> counts;
};


int main() {


    int N;
    std::cin >> N;

    Tree tree(N);

    for (int i = 0; i < N - 1; ++i) {


        int from, to;
        std::cin >> from >> to;
        tree.AddEdge(--from, --to);
    }

    std::vector<int> result = tree.GetSubtreeVerticesCount();

    for (int count : result ) {

        std::cout << count << " ";
    }

    std::cout << std::endl;


    return EXIT_SUCCESS;
}