#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <utility>


struct Item {

    long long val = INT_MIN;
    long long promise = 0;
};

class SegmentTree {

    public:

        SegmentTree(const std::vector<long long>& src) {

            int len = src.size();

            int curr = 1;

            while (curr < len) {
                curr *= 2;
            }

            int needed = curr - len;

            n = curr - 1;

            tree.resize(curr - 1);

            for (int i = 0 ; i < curr; ++i) {

                if (i < src.size() ) {

                    tree.push_back( {src[i], 0});
                }
                else {
                    tree.push_back( {LLONG_MIN, 0} );
                }
            }

            for (int i = curr - 2; i >= 0; --i) {

                int li = 2 * i + 1;
                int ri = 2 * i + 2;

                if (tree[li].val == tree[ri].val) {
                    tree[i].val = tree[li].val;
                }
                else {

                    if (tree[li].val > tree[ri].val) {
                     
                        tree[i].val = tree[li].val;
                        
                    }
                    else {

                        tree[i].val = tree[ri].val;
                    }
                }
            }

        }

        void ProcessQuery(int from, int to) {

            long long res = processQuery(from, to, 0, 0, n);
            std::cout << res << " ";
        }

        long long processQuery(int from, int to, int ind, int start, int end) {

            int len = end - start + 1;

            if (from <= start && to >= end) {

                return tree[ind].val;
            }
            else if (to < start || from > end) {
                return LLONG_MIN;
            }

            
            int lc = 2 * ind  + 1;
            int rc = 2 * ind  + 2;

            if (tree[ind].promise != 0 ) {

                tree[lc].promise += tree[ind].promise;
                tree[rc].promise += tree[ind].promise;

                tree[lc].val += tree[ind].promise;
                tree[rc].val += tree[ind].promise;

                tree[ind].promise = 0;
            }

            long long lmax = processQuery(from, to, lc, start, start + len / 2 - 1 );
            long long rmax = processQuery(from , to, rc, start + len / 2,  end);

            return std::max(lmax, rmax);
        }


        void Update(int from, int to, long long add) {

            update(from, to, 0, 0, n, add);
        }

        void update(int from, int to, int ind, int start, int end, long long add) {

            int len = end - start + 1;

            if ( from <= start && to >= end ) {

                if (len == 1) {

                    tree[ind].val += add;
                    tree[ind].promise = 0;
                }
                else {

                    tree[ind].val += add;
                    tree[ind].promise += add;

                }
                
                return ;
            }
            else if (to < start || from > end) {

                return ;
            }
            
            int lc = 2 * ind  + 1;
            int rc = 2 * ind  + 2;

            if (tree[ind].promise != 0) {

                tree[lc].promise += tree[ind].promise;
                tree[lc].val += tree[ind].promise;
                tree[rc].promise += tree[ind].promise;
                tree[rc].val += tree[ind].promise;
                tree[ind].promise = 0;
            }

            
            update(from, to, lc, start, start + len / 2 - 1, add );
            update(from, to, rc, start + len / 2,  end, add);

            tree[ind].val = std::max( tree[lc].val, tree[rc].val );
        }

       
    private:

        std::vector<Item> tree;
        int n ;
};


int main() {

    int n;
    std::cin >> n;

    std::vector<long long> elems(n);

    for (int i = 0; i < n; ++i) {

        std::cin >> elems[i];
    }

    SegmentTree tree( elems ) ;

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {

        std::string op;

        std::cin >> op;

        if (op == "m") {

            int from, to;
            std::cin >> from >> to;
            tree.ProcessQuery( --from, --to );
        }
        else {

            int from, to; 
            long long val;
            std::cin >> from >> to >> val;
            tree.Update(--from, --to, val);
        }
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}