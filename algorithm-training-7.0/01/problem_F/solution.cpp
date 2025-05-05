#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cassert>

struct Item {
    int cost;
    int index;
};

int main() {

    int N, M;
    std::cin >> N >> M;

    std::vector<int> w(N);

    for (int i = 0; i < N; ++i) {

        std::cin >> w[i];
    }

    std::vector<int> c(N);

    for (int i = 0; i < N; ++i) {

        std::cin >> c[i];
    }


    std::vector< std::vector<Item> > dp( 1, std::vector<Item>( M + 1, {-1, -1} ) );
    dp[0][0] = {0, 0};

    int best_cost = 0;
    int best_weight = 0;
    int best_last = 0; 

    for (int i = 0; i < N; ++i) {

        dp.push_back( dp.back() );


        for (int j = M - w[i]; j >= 0; --j) {

            if (dp.back()[j].cost != -1) {

                if (dp.back()[ j + w[i] ].cost < dp.back()[j].cost + c[i] ) {

                    dp.back()[ j + w[i] ] = { dp.back()[j].cost + c[i], i+1 } ;

                    if (dp.back()[ j + w[i] ].cost > best_cost) {
                        best_cost = dp.back()[ j + w[i] ].cost ;
                        best_weight = j + w[i];
                        best_last = i+1;
                    }
                }

            }
        }
    }

    std::vector<int> ans;

    int curr_weight = best_weight;
    int curr_ind = best_last;
    
    while(  curr_ind != 0 ) {

        ans.push_back(curr_ind);

        curr_weight -= w[curr_ind-1] ;
        curr_ind = dp[curr_ind-1][curr_weight].index;
    }
    
    assert( curr_weight == 0  );

    std::reverse( ans.begin(), ans.end() ) ;

    for (int ai : ans) {
        std::cout << ai << std::endl;
    }


    return EXIT_SUCCESS;
}