#include <iostream>
#include <vector>


using Graph = std::vector<std::vector<int>>;


void generate(std::vector<int>& nums, int l, int r, int& best_ans, const Graph& g, int curr_len) {

    if (l == r) {

        int dist =  l == 0 ?  g[0][nums[l]] : g[nums[l-1]][nums[l]] ;

        if (dist == 0) {
            return;
        }

        curr_len += dist;

        if ( g[nums[l]][0] != 0) {

            curr_len += g[nums[l]][0];

            if ( best_ans == -1 || curr_len < best_ans) {
                best_ans = curr_len;
            }
        }
    }
    else {

        for (int i = l ; i < r+1; ++i) {

            std::swap(nums[l], nums[i]);

            int dist =  l == 0 ?  g[0][nums[l]] : g[nums[l-1]][nums[l]] ;

            if ( dist != 0 && ( best_ans == -1 || curr_len + dist < best_ans   ) ) {

                generate(nums, l+1, r, best_ans, g, curr_len + dist );
            }

            std::swap(nums[i], nums[l]);
        }
    }
}



int main() {

    int N;
    std::cin >> N;

    Graph g(N, std::vector<int>(N, 0) ) ;

    for (int i = 0; i < N; ++i) {

        for (int j = 0; j < N; ++j) {

            std::cin >> g[i][j] ;
        }
    }

    if (N == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }


    std::vector<int> nums(N-1);
    for (int i = 0; i < N-1; ++i) {
        nums[i] = i+1;
    }
    
    int best_ans = -1;
    
    generate(nums, 0, N-2, best_ans, g, 0);

    std::cout << best_ans << std::endl;

    return 0;
}