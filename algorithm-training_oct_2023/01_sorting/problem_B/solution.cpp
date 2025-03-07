#include <iostream>
#include <vector>
#include <cstdlib>
#include <functional>
#include <ctime>

namespace algo {

    template<class InputIt, class UnaryPred>
    constexpr InputIt find_if_not(InputIt first, InputIt last, UnaryPred q)
    {
        for (; first != last; ++first)
            if (!q(*first))
                return first;
    
        return last;
    }

    template<class ForwardIt, class UnaryPred>
    ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPred p)
    {
        first = algo::find_if_not(first, last, p);
        if (first == last)
            return first;
    
        for (auto i = std::next(first); i != last; ++i)
            if (p(*i))
            {
                std::iter_swap(i, first);
                ++first;
            }
    
        return first;
    }

    template<class RandomIt, class Compare>
    void quicksort( RandomIt first, RandomIt last, Compare comp ) {

        if (first == last) {
            return;
        }
        
        const int random_value = std::rand();
        int distance = std::distance(first, last);

        auto pivot = *std::next(first, random_value % distance);

        auto middle1 = algo::partition(first, last, [&comp, pivot](const auto& em) { return comp(em, pivot); } );
        auto middle2 = algo::partition(middle1, last, [&comp, pivot](const auto& em) { return !comp(pivot, em); });
    
        quicksort(first, middle1, comp);
        quicksort(middle2, last, comp);
    }

}

int main() {

    int N;
    std::cin >> N;

    std::vector<int> a(N);

    for (int i = 0; i < N; ++i) {

        std::cin >> a[i];
    }

    std::srand(1) ;

    algo::quicksort( a.begin(), a.end(), std::less<int>{} );

    for (const int& ai : a) {
        std::cout << ai << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}