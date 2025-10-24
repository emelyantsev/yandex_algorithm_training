#include <iostream>
#include <vector>

class Solution {
    
public:

    Solution(int n) : n(n), root(-1) {
        children.resize(n + 1);
        time.resize(n + 1, std::vector<int>(2, -1));
    }
    
    void build_tree(const std::vector<int>& parents) {
        
        for (int i = 0; i < n; i++) {
            if (parents[i] == 0) {
                root = i + 1;
            }
            children[parents[i]].push_back(i + 1);
        }
        
        _process(root, 0);
    }
    
    bool is_ansector(int a, int b) {
        
        std::vector<int>& at = time[a];
        std::vector<int>& bt = time[b];
        
        if (bt[0] > at[0] && bt[1] <= at[1]) {
            return true;
        } else {
            return false;
        }
    }

private:

    int _process(int node, int t) {
        
        time[node][0] = t;
        int curr_time = t;
        
        for (int child : children[node]) {
            curr_time = _process(child, curr_time + 1);
        }
        
        time[node][1] = curr_time;
        return curr_time;
    }
    
    int n;    
    std::vector<std::vector<int>> children;
    int root;
    std::vector<std::vector<int>> time;
    
};

int main() {

    int n;
    std::cin >> n;
    
    Solution sln(n);
    
    std::vector<int> parents(n);

    for (int i = 0; i < n; i++) {
        std::cin >> parents[i];
    }
    
    sln.build_tree(parents);
    
    int m;
    std::cin >> m;
    
    for (int i = 0; i < m; i++) {

        int a, b;
        std::cin >> a >> b;
        std::cout << ( sln.is_ansector(a, b) ? 1 : 0 ) << std::endl;
    }
    
    return 0;
}