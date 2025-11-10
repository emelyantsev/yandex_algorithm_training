#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <map>
#include <cassert>
#include <queue>
#include <climits>
#include <sstream>

struct Item {

    int val = INT_MAX;
    int index = -1;    
};

class SegmentTree {

    public:

        SegmentTree() = default;

        SegmentTree(const std::vector<Item>& src) {

            int len = src.size();

            int curr = 1;

            while (curr < len) {
                curr *= 2;
            }

            n = curr - 1;

            tree.resize(curr - 1);

            for (int i = 0 ; i < curr; ++i) {

                if (i < src.size() ) {

                    tree.push_back( src[i] );
                }
                else {
                    tree.push_back( {INT_MAX, -1} );
                }
            }

            for (int i = curr - 2; i >= 0; --i) {

                int li = 2 * i + 1;
                int ri = 2 * i + 2;

                if (tree[li].val <= tree[ri].val) {
                     
                    tree[i].val = tree[li].val;
                    tree[i].index = tree[li].index;
                }
                else {

                    tree[i].val = tree[ri].val;
                    tree[i].index = tree[ri].index;
                }

            }

        }

        int ProcessQuery(int from, int to) const {

            Item item = processQuery(from, to, 0, 0, n);
            return item.index;

        }

        Item processQuery(int from, int to, int ind, int start, int end) const {

            if (from <= start && to >= end) {
                return tree[ind];
            }
            else if (to < start || from > end) {
                return {INT_MAX, -1};
            }

            int len = end - start + 1;

            int lc = 2 * ind  + 1;
            int rc = 2 * ind + 2;

            Item li = processQuery( from, to, lc, start, start + len / 2 - 1 );
            Item ri = processQuery( from , to, rc, start + len / 2,  end );

            if ( li.val <= ri.val ) {
                return { li.val, li.index };
            }
            else {
                return { ri.val, ri.index } ;
            }
        }

    private:

        std::vector<Item> tree;
        int n ;
};



class Solution {

    public:

        Solution(int n) : n(n),  is_child(n, false), first_index(n, -1), children_of(n), heights(n, -1) {

            names.reserve(n);
        }

        void AddPair(const std::string& child, const std::string& parent) {

            int child_id = getId( child );
            int parent_id = getId( parent );

            children_of[parent_id].push_back(child_id);
            is_child[child_id] = true;
        }

        const std::string& GetLCA(const std::string& name1, const std::string& name2) const {

            int id1 = getId( name1 );
            int id2 = getId( name2 );

            int ind1 = first_index[id1];
            int ind2 = first_index[id2];

            int res_ind = segTree.ProcessQuery(std::min(ind1, ind2), std::max(ind1, ind2) );

            return names[res_ind];
        }

        void CalcMinimums() {
         
            root = getRoot();

            calcHeights(root, 0);
            walk(root);

            std::vector<Item> items;

            for (int i = 0; i < indexes.size(); ++i) {

                items.push_back( { heights[indexes[i] ], indexes[i]  });
            }

            segTree = SegmentTree( items ) ;
        }


    private:

        int getId(const std::string& name) const {

            const std::string_view name_ = name;
           
            if (names_indexes.count(name_) == 1 ) {
                return names_indexes[name_];
            }

            else {

                names.push_back(name);

                const std::string_view new_name_ = names.back();

                names_indexes[new_name_] = names.size() - 1;
                return names.size() - 1;
            }
        }

        int getRoot() {

            int cnt = 0;
            int res = -1;

            for (int i = 0; i < n; ++i) {

                if (is_child[i] == false) {
                    ++cnt;
                    res = i;
                }
            }

            assert( cnt == 1 );
            return res;
        }

        void walk(int ind) {

            indexes.push_back(ind);
            first_index[ind] = indexes.size() - 1;

            for (int child_ind : children_of[ind]) {

                walk(child_ind);
                indexes.push_back(ind);
            }
        }

        void calcHeights(int ind, int h) {

            heights[ind] = h;

            for (int child_ind : children_of[ind]) {

                calcHeights(child_ind, h+1);
            }
        }


        mutable std::vector<std::string> names;
        mutable std::map<std::string_view, int> names_indexes;
        
        std::vector<bool> is_child;
        std::vector<std::vector<int> > children_of; 
        std::vector<int> first_index;
        std::vector<int> indexes;
        std::vector<int> heights;

        int n;
        int root;

        SegmentTree segTree;
};


int main() {

    int n;
    std::cin >> n;

    Solution sln(n) ;

    for (int i = 0; i < n - 1; ++i) {

        std::string child, parent;
        std::cin >> child >> parent;
        sln.AddPair(child, parent);
    }

    sln.CalcMinimums();

    std::string line;
    std::getline(std::cin, line) ;

    while ( std::getline(std::cin, line) ) {

        std::istringstream iss( line );
        std::string name1, name2;
        iss >> name1 >> name2;

        std::cout << sln.GetLCA(name1, name2) << std::endl;
    }

    return 0;
}
