#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <cmath>

int main() {


    int n, H;
    std::cin >> n >> H;

    std::vector<int> h(n), w(n);
    
    for (int i = 0; i < n; ++i) {

        std::cin >> h[i];
    }

    for (int i = 0; i < n; ++i) {

        std::cin >> w[i];
    }

    std::vector<std::tuple<int, int> > items;

    for (int i = 0; i < n; ++i) {

        items.push_back({h[i], w[i]});
    }

    std::sort(items.begin(), items.end() );

    int cur_sum_w = std::get<1>( items[0] );
    int i = 0;

    int max_diff_h = 0;

    std::map<int, int> height_diffs;


    while (cur_sum_w < H) {
        
        i += 1;
        cur_sum_w += std::get<1>( items[i] );

        int curr_diff = std::abs( std::get<0>( items[i-1] ) - std::get<0>( items[i] ) ) ;

        height_diffs[curr_diff] += 1;
        max_diff_h = std::max(max_diff_h, curr_diff);
    }

    int l = 0;
    int r = i;

    while (true) {

        if (cur_sum_w >= H) {

            if (l == n - 1 ) {
                break;
            }


            if (l == r) {

                ++l;
                ++r;

                cur_sum_w = std::get<1>( items[l]);
                max_diff_h = 0;

            }
            else {

                ++l;

                int curr_diff = std::abs( std::get<0>( items[l-1] ) - std::get<0>( items[l] ) ) ;
                cur_sum_w -= std::get<1>( items[l-1] );

                height_diffs[curr_diff] -= 1;

                if (height_diffs[curr_diff] == 0) {                    
                    height_diffs.erase(curr_diff);
                }

                if ( cur_sum_w >= H) {

                    int max_diff = height_diffs.size() > 0 ? std::prev(height_diffs.end())->first : 0;
                    max_diff_h = std::min( max_diff_h, max_diff) ;
                }
            }
        }
        else {

            if (r == n-1) {
                break;
            }

            ++r; 
            int curr_diff = std::abs( std::get<0>( items[r-1] ) - std::get<0>( items[r] ) ) ;
            cur_sum_w += std::get<1>( items[r] );

            height_diffs[curr_diff] += 1;

            if ( cur_sum_w >= H) {

                int max_diff = std::prev(height_diffs.end())->first;
                max_diff_h = std::min( max_diff_h, max_diff) ;
            }
        }

    } 
    


    std::cout << max_diff_h << std::endl;


    return 0;
}