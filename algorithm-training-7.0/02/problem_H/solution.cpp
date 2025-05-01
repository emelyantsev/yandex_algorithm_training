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

        void ProcessQuery(int ind) {

            processQuery(ind, 0, 0, n);
        }

        void processQuery(int ind, int tree_ind, int start, int end) {

            while (true) {

                if (ind + n == tree_ind) {
                    std::cout << tree[tree_ind].val + tree[tree_ind].promise << std::endl;
                    return;
                }

                int lc = 2 * tree_ind  + 1;
                int rc = 2 * tree_ind  + 2;


                if (tree[tree_ind].promise != 0 ) {

                  //  tree[lc].val += tree[tree_ind].promise;
                    tree[lc].promise += tree[tree_ind].promise;
    
                  //  tree[rc].val += tree[tree_ind].promise;
                    tree[rc].promise += tree[tree_ind].promise;
    
                    tree[tree_ind].promise = 0;
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


        void Update(int from, int to, long long add) {

            update(from, to, 0, 0, n, add);
        }

        void update(int from, int to, int ind, int start, int end, long long add) {

            int len = end - start + 1;

            if ( from <= start && to >= end ) {

                tree[ind].promise += add;
                return ;
            }
            else if (to < start || from > end) {
                return ;
            }

            
            int lc = 2 * ind  + 1;
            int rc = 2 * ind  + 2;


            if (tree[ind].promise != 0) {

                //tree[lc].val += tree[ind].promise;
                tree[lc].promise += tree[ind].promise;

                //tree[rc].val += tree[ind].promise;
                tree[rc].promise += tree[ind].promise;

                tree[ind].promise = 0;
            }

            
            update(from, to, lc, start, start + len / 2 - 1, add );
            update(from, to, rc, start + len / 2,  end, add);

            //tree[ind].val = std::max( tree[lc].val, tree[rc].val );
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

        if (op == "g") {

            int ind;
            std::cin >> ind;
            tree.ProcessQuery( --ind );
        }
        else {

            int from, to; 
            long long val;
            std::cin >> from >> to >> val;
            tree.Update(--from, --to, val);
        }
    }


    return EXIT_SUCCESS;
}