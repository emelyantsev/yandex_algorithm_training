#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <utility>


struct Item {

    long long val = 0;
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

                    tree.push_back( { src[i] });
                }
                else {
                    tree.push_back( { 0} );
                }
            }

            // for (int i = curr - 2; i >= 0; --i) {

            //     int li = 2 * i + 1;
            //     int ri = 2 * i + 2;

            //     if (tree[li].val == tree[ri].val) {
            //         tree[i].val = tree[li].val;
            //     }
            //     else {

            //         if (tree[li].val > tree[ri].val) {
                     
            //             tree[i].val = tree[li].val;
                        
            //         }
            //         else {

            //             tree[i].val = tree[ri].val;
            //         }
            //     }
            // }

        }

        void ProcessQuery(int l, int r, int k) {

            bool res = true;

            for (int i = 0; i < k; ++i) {

                if (GetVal(l+i) != GetVal(r+i) ) {
                    res = false;
                    break;
                }
            }

            std::cout << (res ? '+' : '-') ;
        }

        long long GetVal(int ind) {

            return getVal(ind, 0, 0, n);
        }

        long long getVal(int ind, int tree_ind, int start, int end) {

            while (true) {

                if (ind + n == tree_ind) {

                    return tree[tree_ind].val;
                }

                int lc = 2 * tree_ind  + 1;
                int rc = 2 * tree_ind  + 2;


                if (tree[tree_ind].val != 0 ) {

                    tree[lc].val = tree[tree_ind].val;
                    tree[rc].val = tree[tree_ind].val;
                    tree[tree_ind].val = 0;
                }

                int len = end - start + 1;

                if (ind <= start + len / 2 - 1) {
                    end = start + len / 2 - 1 ;
                    tree_ind = lc;
                }
                else {
                    start = start + len / 2 ;
                    tree_ind = rc;
                }
            }
        }


        void Update(int from, int to, long long val) {

            update(from, to, 0, 0, n, val);
        }

        void update(int from, int to, int ind, int start, int end, long long val) {

            int len = end - start + 1;

            if ( from <= start && to >= end ) {

                tree[ind].val = val;
                return ;
            }
            else if (to < start || from > end) {
                return ;
            }

            
            int lc = 2 * ind  + 1;
            int rc = 2 * ind  + 2;


            if (tree[ind].val != 0) {

                tree[lc].val = tree[ind].val; 
                tree[rc].val = tree[ind].val;
                tree[ind].val = 0;
            }

            
            update(from, to, lc, start, start + len / 2 - 1, val );
            update(from, to, rc, start + len / 2,  end, val);
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

    // for (int i = 1; i <= n; ++i ) {
    //     std::cout << tree.GetVal(i-1) << " ";
    // }
    // std::cout << std::endl;

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {

        int op;

        std::cin >> op;

        if (op == 1) {

            int l, r, k;
            std::cin >> l >> r >> k;
            tree.ProcessQuery( --l, --r, k );
        }
        else {

            int l, r, k;
            std::cin >> l >> r >> k;
            tree.Update(--l, --r, k);

            // for (int i = 1; i <= n; ++i ) {
            //     std::cout << tree.GetVal(i-1) << " ";
            // }
            // std::cout << std::endl;
        }
    }

    
    std::cout << std::endl;

    return EXIT_SUCCESS;
}