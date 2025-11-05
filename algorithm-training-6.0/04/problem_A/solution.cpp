#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <map>
#include <cassert>
#include <queue>

class Solution {

    public:

        Solution(int n) : n(n),  is_child(n, false), heights(n, -1), children_of(n) {

            names.reserve(n);
        }

        void AddPair(const std::string& child, const std::string& parent) {

            int child_id = getId( child );
            int parent_id = getId( parent );

            children_of[parent_id].push_back(child_id);
            is_child[child_id] = true;
        }

        void PrintHeights() {

            calcHeights();

            for ( auto& [name_, id] : names_indexes ) {
                std::cout << name_ << " " << heights[id] << std::endl;
            }
        }


    private:

        int getId(const std::string& name) {

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

        void calcHeights() {

            int curr = getRoot();
            heights[curr] = 0;

            std::queue<int> q;
            q.push(curr);

            while (!q.empty()) {

                curr = q.front();
                q.pop();

                for (int child_id : children_of[curr] ) {

                    heights[child_id] = heights[curr]+1;
                    q.push(child_id); 
                }
            }
        }



        std::vector<std::string> names;
        std::vector<bool> is_child;
        std::vector<int> heights;
        std::map<std::string_view, int> names_indexes;
        std::vector<std::vector<int> > children_of; 
        int n;
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

    sln.PrintHeights();


    return 0;
}
