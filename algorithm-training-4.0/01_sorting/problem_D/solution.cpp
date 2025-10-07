#include <iostream>
#include <cstdlib>
#include <vector>


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

    template<class RandomIt, class Compare>
    void merge_sort( RandomIt first, RandomIt last, Compare comp ) {

        if (first == last) {
            return;
        }
        
        int len = std::distance(first, last);

        int step_len = 1;

        while ( step_len < len ) {

            RandomIt start1 = first;

            while (true) {

                RandomIt end1 = start1 + step_len;
                RandomIt start2 = end1;
                RandomIt end2 = start2 + std::min( step_len, (int) std::distance(start2, last) );

                using T = std::remove_reference<decltype(*first)>::type;

                std::vector< T > merged_elements;
                
                algo::merge(start1, end1, start2, end2, std::back_inserter(merged_elements), comp);


                for (const auto elem : merged_elements) {
                    *start1 = elem;
                    ++start1;
                }

                int rem_len = std::distance(start1, last);

                if (rem_len <= step_len) {
                    break;
                }

            }

            step_len *= 2;

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

    algo::merge_sort(a.begin(), a.end(), std::less<int>{}) ;

    for (int ai : a) {

        std::cout << ai << " ";
    }

    std::cout << std::endl;


    return EXIT_SUCCESS;
}