#include <iostream>
#include <vector>


int main() {


    int N;
    std::cin >> N;

    

    std::vector<std::vector<int>> g(N, std::vector<int>(N, 0) ) ;

    for (int i = 0; i < N; ++i) {

        for (int j = 0; j < N; ++j) {

            std::cin >> g[i][j] ;
        }
    }

    int best_res = 0;
    int best_set = 0;

    for (int set = 1; set < (1 << N ) ; ++set) {

        int cur_res = 0;

        for (int i = 0 ; i < N + 1; ++i) {

            int ind1 = ( set & (1 << i) ) > 0 ? 1 : 0 ;

            for (int j = i + 1; j < N; ++j) {

                int ind2 = ( set & (1 << j) ) > 0 ? 1 : 0 ;

                if (ind1 != ind2 ) {
                    cur_res += g[i][j];
                }

            }

        }

        if (cur_res > best_res) {
            best_res = cur_res;
            best_set = set;
        }
    }

    std::cout << best_res << std::endl;

    for (int i = 0 ; i < N; ++i) {

        int ind = ( best_set & (1 << i) ) > 0 ? 1 : 0 ;
        std::cout << ind + 1 << " ";
    }

    std::cout << std::endl;



    return 0;
}