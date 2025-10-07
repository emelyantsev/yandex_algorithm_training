#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>

namespace algo {


    template<class ForwardIt, class InsertIt, class Compare>
    void merge(ForwardIt lbegin, ForwardIt lend, ForwardIt rbegin, ForwardIt rend, InsertIt to, Compare cmp) {

        while ( lbegin != lend || rbegin != rend) {

            if (lbegin == lend && rbegin != rend) {
                *to = *rbegin;
                ++to;
                ++rbegin;
            }
            else if (lbegin != lend && rbegin == rend) {
                *to = *lbegin;
                ++to;
                ++lbegin;
            }
            else {
    
                if (cmp(*lbegin, *rbegin)) {
                    *to = *lbegin;
                    ++to;
                    ++lbegin;
                }
                else {
                    *to = *rbegin;
                    ++to;
                    ++rbegin;
                }
            }
        }
    } 
}

int main() {

    int N;
    std::cin >> N;

    std::vector<int> a(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }

    int M;
    std::cin >> M;
    std::vector<int> b(M);

    for (int i = 0; i < M; ++i) {
        std::cin >> b[i];
    }

    std::vector<int> result;
    result.reserve(N+M);

    algo::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result), std::less<int>{} ) ;

    for (int ri : result) {
        std::cout << ri << " " ;
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}