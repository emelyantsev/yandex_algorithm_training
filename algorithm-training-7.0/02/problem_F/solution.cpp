#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <utility>


struct Item {

    int val = INT_MIN;
};

class SegmentTree {

    public:

        SegmentTree(const std::vector<int>& src) {

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

                    tree.push_back( {src[i]});
                }
                else {
                    tree.push_back( {INT_MIN} );
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

        void ProcessQuery(int ind, int val) {

            int curr = ind + n;

            if (tree[curr].val >= val) {

                std::cout << curr - n + 1 << std::endl;
                return ;
            }

            while (true) {

                if (curr == 0) {
                    std::cout << -1 << std::endl;
                    return ;
                }

                int par = curr % 2 == 0 ? (curr - 2) / 2 : (curr - 1) / 2;

                if ( tree[par].val >= val && ( curr == 2 * par + 1) && tree[2 * par + 2].val >= val ) {

                    curr = 2 * par + 2;

                    while (true) {

                        if (2 * curr + 1 >= tree.size() ) {

                            std::cout << curr - n + 1 << std::endl;
                            return ;
                        }

                        if (tree[2*curr+1].val >= val) {
                            curr = 2*curr+1;
                        }
                        else {
                            curr = 2*curr+2;
                        }

                    }

                }
                else {

                    curr = par;
                }

            }


        }

        void Update(int ind, int val) {

            int curr = n + ind; 

            tree[curr].val = val;

            while (curr != 0) {

                int par = curr % 2 == 0 ? (curr - 2) / 2 : (curr - 1) / 2;

                int lc = 2 * par + 1;
                int rc = 2 * par + 2;

                tree[par].val = std::max( tree[lc].val, tree[rc].val) ;

                if (tree[lc].val == tree[rc].val) {
                    tree[par].val = tree[lc].val;
                }
                else {

                    if (tree[lc].val > tree[rc].val) {
                     
                        tree[par].val = tree[lc].val;
                    }
                    else {

                        tree[par].val = tree[rc].val;
                    }
                }

                curr = par;
            }

        }

       
    private:

        std::vector<Item> tree;
        int n ;
};


int main() {

    int n, m;
    std::cin >> n >> m;

    std::vector<int> elems(n);

    for (int i = 0; i < n; ++i) {

        std::cin >> elems[i];
    }

    SegmentTree tree( elems ) ;

    for (int i = 0; i < m; ++i) {

        int op;

        std::cin >> op;

        if (op == 1) {

            int ind, val;
            std::cin >> ind >> val;
            tree.ProcessQuery( --ind, val );
        }
        else {

            int ind, val;

            std::cin >> ind >> val;

            tree.Update(--ind, val);

        }
    }


    return EXIT_SUCCESS;
}