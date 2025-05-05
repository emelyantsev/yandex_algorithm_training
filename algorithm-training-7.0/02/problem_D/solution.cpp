#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <utility>
#include <string>

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

                    tree.push_back( {src[i] });
                }
                else {
                    tree.push_back( { INT_MIN } );
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

            Item item = processQuery(from, to, 0, 0, n);
            std::cout << item.val << " ";

        }

        void Update(int ind, int val) {

            int curr = n + ind; 

            tree[curr].val = val;

            while (curr != 0) {

                int par = curr % 2 == 0 ? (curr - 2) / 2 : (curr - 1) / 2;

                int lc = 2 * par + 1;
                int rc = 2 * par + 2;

                tree[par].val = std::max( tree[lc].val, tree[rc].val) ;
                curr = par;
            }

        }

        Item processQuery(int from, int to, int ind, int start, int end) {

            if (from <= start && to >= end) {
                return tree[ind];
            }
            else if (to < start || from > end) {
                return {INT_MIN};
            }

            int len = end - start + 1;

            int lc = 2 * ind  + 1;

            int rc = 2 * ind + 2;

            Item li = processQuery(from, to, lc, start, start + len / 2 - 1 );
            Item ri = processQuery(from , to, rc, start + len / 2,  end);

            if (li.val == ri.val) {
                return {li.val} ;
            }
            else if (li.val > ri.val) {

                return { li.val };
            }
            else {
                return { ri.val } ;
            }
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

    SegmentTree tree(elems) ;

    int k;
    std::cin >> k;

    for (int i = 0; i < k; ++i) {

        std::string op;
        int from, to;

        std::cin >> op >> from >> to;

        if (op == "s") {
            tree.ProcessQuery(--from, --to);
        }
        else {
            tree.Update(--from, to);
        }
        
    }

    std::cout << std::endl;


    return EXIT_SUCCESS;
}