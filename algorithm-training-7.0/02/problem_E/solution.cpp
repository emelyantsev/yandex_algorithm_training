#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <utility>


struct Item {

    int val = INT_MAX;
    int count = 1;    
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

                    tree.push_back({src[i], 1});
                }
                else {
                    tree.push_back({INT_MAX, 1} );
                }
            }

            for (int i = curr - 2; i >= 0; --i) {

                int li = 2 * i + 1;
                int ri = 2 * i + 2;

                if (tree[li].val == tree[ri].val) {
                    tree[i].val = tree[li].val;
                    tree[i].count = tree[li].count + tree[ri].count;
                }
                else {

                    if (tree[li].val < tree[ri].val) {
                     
                        tree[i].val = tree[li].val;
                        tree[i].count = tree[li].count;
                    }
                    else {

                        tree[i].val = tree[ri].val;
                        tree[i].count = tree[ri].count;
                    }
                }
            }

        }

        void ProcessQuery(int from, int to, int k) {

            if ( GetCount(from, to) < k ) {
                std::cout << "-1" << std::endl;
                return;
            }

            int ind = GetIndex(k + (from == 0 ? 0 : GetCount(0, from - 1)) );

            std::cout << ind << std::endl;

        }

        int GetIndex(int k) {

            int curr_index = 0;

            Item item = tree[curr_index];

            while (true) {

                int li = 2 * curr_index + 1;
                int ri = 2 * curr_index + 2;

                if (li >= tree.size() ) {
                    return curr_index - n + 1;
                }
                else {

                    int lc = tree[li].val == 0 ?  tree[li].count : 0;
                    int rc = tree[ri].count;

                    if (k <= lc) {
                        curr_index = li;
                    }
                    else {
                        k -= lc;
                        curr_index = ri;
                    }

                }
            }

        }

        void Update(int ind, int val) {

            int curr = n + ind; 

            tree[curr].val = val;
            tree[curr].count = 1;

            while (curr != 0) {

                int par = curr % 2 == 0 ? (curr - 2) / 2 : (curr - 1) / 2;

                int lc = 2 * par + 1;
                int rc = 2 * par + 2;

                tree[par].val = std::min( tree[lc].val, tree[rc].val) ;

                if (tree[lc].val == tree[rc].val) {
                    tree[par].val = tree[lc].val;
                    tree[par].count = tree[lc].count + tree[rc].count;
                }
                else {

                    if (tree[lc].val < tree[rc].val) {
                     
                        tree[par].val = tree[lc].val;
                        tree[par].count = tree[lc].count;
                    }
                    else {

                        tree[par].val = tree[rc].val;
                        tree[par].count = tree[rc].count;
                    }
                }

                curr = par;
            }

        }

        int GetCount(int from, int to) {

            return getCount(from, to, 0, 0, n);
        }

        int getCount(int from, int to, int ind, int start, int end) {

            if (from <= start && to >= end && tree[ind].val == 0) {
                return tree[ind].count;
            }
            else if (from <= start && to >= end && tree[ind].val != 0){
                return 0;
            }
            else if (to < start || from > end) {
                return 0;
            }

            int len = end - start + 1;

            int li = 2 * ind  + 1;

            int ri = 2 * ind + 2;

            int lc = getCount( from, to, li, start, start + len / 2 - 1 );
            int rc = getCount( from , to, ri, start + len / 2,  end);

            return lc + rc;
        }

    private:

        std::vector<Item> tree;
        int n ;
};


int main() {

    int n;
    std::cin >> n;

    std::vector<int> elems(n);

    for (int i = 0; i < n; ++i) {

        std::cin >> elems[i];
    }

    SegmentTree tree( elems ) ;

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {

        std::string op;

        std::cin >> op;

        if (op == "s") {

            int from, to, k;
            std::cin >> from >> to >> k;
            tree.ProcessQuery( --from, --to, k );
        }
        else {

            int ind, val;

            std::cin >> ind >> val;

            tree.Update(--ind, val);

        }

        
    }


    return EXIT_SUCCESS;
}