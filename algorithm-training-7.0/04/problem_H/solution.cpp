#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <string>


class DSU {

    public:

        DSU(int n) : h(n, 0), p(n, 0) {

            for (int i = 0; i < n; ++i) {
                p[i] = i;
            }
        }

        void Join(int v1, int v2) {

            int p1 = parent(v1);
            int p2 = parent(v2);

            if (p1 == p2) {
                return;
            }

            if (h[p1] < h[p2]) {
                std::swap(p1, p2);
            }

            assert( h[p1] >= h[p2] ) ;

            p[p2] = p1;

            if (h[p1] == h[p2]) {
                ++h[p1];
            }
        }

        bool IsSame(int v1, int v2) {

            return parent(v1) == parent(v2);
        }

    private:

        int parent(int v) {

            while (p[v] != v) {
                v = p[v];
            }

            return v;
        }

        std::vector<int> h;
        std::vector<int> p;
};

struct Operation {

    enum class Type {
        ASK,
        CUT
    }; 

    Type type;
    int u;
    int v;
};


int main() {

    int n, m, k;

    std::cin >> n >> m >> k;

    DSU dsu(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
    }

    std::vector<Operation> operations;

    for (int i = 0; i < k; ++i) {

        std::string type;
        int u, v;

        std::cin >> type >> u >> v;

        operations.emplace_back( type == "ask" ? Operation::Type::ASK : Operation::Type::CUT, u-1, v-1   );
    }


    std::vector<bool> ans;

    for (auto it = operations.rbegin(); it != operations.rend(); ++it) {

        Operation& op = *it;

        if (op.type == Operation::Type::ASK) {

            ans.push_back( dsu.IsSame( op.u, op.v ) ) ;
        }
        else {
            dsu.Join(op.u, op.v);
        }
    }

    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {


        std::cout << ( *it ? "YES" : "NO" ) << std::endl;
    }


    return EXIT_SUCCESS;
}