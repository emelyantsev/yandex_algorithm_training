#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <utility>


struct Item {

    int len = 1;
    int prefix = 0;
    int suffix = 0;
    int inner = 0;
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

                    if (src[i] == 0) {

                        tree.push_back( {1, 1, 1, 1});
                    }
                    else {
                        tree.push_back( {1, 0, 0, 0});
                    }
                    
                }
                else {
                    tree.push_back( {1, 0, 0, 0} );
                }
            }

            for (int i = curr - 2; i >= 0; --i) {

                int li = 2 * i + 1;
                int ri = 2 * i + 2;

                Item& item = tree[i];

                item.prefix = tree[li].prefix == tree[li].len ? tree[li].len + tree[ri].prefix : tree[li].prefix;
                item.suffix = tree[ri].suffix == tree[ri].len ? tree[li].suffix + tree[ri].len : tree[ri].suffix;

                item.inner = std::max( tree[li].suffix + tree[ri].prefix, std::max( tree[li].inner, tree[ri].inner ) );
                item.len = 2 * tree[li].len;
            }

        }

        void ProcessQuery(int from, int to) {

            Item item = processQuery(from, to, 0, 0, n);
            std::cout << std::max(item.inner, std::max(item.prefix, item.suffix) ) << std::endl;
        }

        Item processQuery(int from, int to, int ind, int start, int end) {

            int len = end - start + 1;

            if (from <= start && to >= end) {

                return tree[ind];
            }
            else if (to < start || from > end) {
                
                return {0, 0, 0, 0,};
            }

            
            int lc = 2 * ind  + 1;
            int rc = 2 * ind  + 2;

            
            Item li = processQuery(from, to, lc, start, start + len / 2 - 1 );
            Item ri = processQuery(from , to, rc, start + len / 2,  end);

            Item item;

            item.prefix = li.prefix == li.len ? li.len + ri.prefix : li.prefix;
            item.suffix = ri.suffix == ri.len ? li.suffix + ri.len : ri.suffix;

            item.inner = std::max( li.suffix + ri.prefix, std::max( li.inner, ri.inner ) ) ;
            item.len = li.len + ri.len;

            return item;
        }


        void Update(int ind, int val) {

            update(ind, val);
        }

        void update(int ind, int val) {

            int curr = ind + n;

            if (val == 0 && tree[curr].inner == 1 || val != 0 && tree[curr].inner == 0) {
                return;
            }
            else {

                if (val == 0) {

                    tree[curr].inner = 1;
                    tree[curr].prefix = 1;
                    tree[curr].suffix = 1;
                }
                else {
                    tree[curr].inner = 0;
                    tree[curr].prefix = 0;
                    tree[curr].suffix = 0;
                }
            }

            while (curr != 0) {

                int par = curr % 2 == 0 ? (curr - 2) / 2 : (curr - 1) / 2;

                int li = 2 * par + 1;
                int ri = 2 * par + 2;

                Item& item = tree[par];

                item.prefix = tree[li].prefix == tree[li].len ? tree[li].len + tree[ri].prefix : tree[li].prefix;
                item.suffix = tree[ri].suffix == tree[ri].len ? tree[li].suffix + tree[ri].len : tree[ri].suffix;

                item.inner = std::max( tree[li].suffix + tree[ri].prefix, std::max( tree[li].inner, tree[ri].inner ) )  ;
                
                curr = par;
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

    SegmentTree tree( elems ) ;

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {

        std::string op;

        std::cin >> op;

        if (op == "QUERY") {

            int from, to;
            std::cin >> from >> to;
            tree.ProcessQuery( --from, --to );
        }
        else {

            int ind, val;
            std::cin >> ind >> val;
            tree.Update(--ind, val);
        }
    }

    return EXIT_SUCCESS;
}