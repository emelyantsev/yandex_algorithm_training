#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_set>
#include <cassert>

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

        int GetCount() {

            int res = 0;

            for (int i = 0; i < p.size(); ++i) {
                
                if (p[i] == i) {
                    ++res;
                } 
            }

            return res;
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


int main() {


    int n, m;

    std::cin >> n >> m;

    DSU dsu(n);

    int count = 0;

    for (int i = 0; i < m; ++i) {

        int x, y;
        std::cin >> x >> y ;
        --x; --y;

        dsu.Join(x, y);
        ++count;
        if (dsu.GetCount() == 1) {
            break;
        }
    }

    std::cout << count << std::endl;


    return EXIT_SUCCESS;
}