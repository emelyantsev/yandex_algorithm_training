#include <iostream>
#include <vector>
#include <cstdlib>

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

}

int main() {

    int N;
    std::cin >> N;

    std::vector<int> nums(N);

    for (int i = 0; i < N; ++i) {

        std::cin >> nums[i];
    }

    int x;
    std::cin >> x;

    auto pred = [&x](int val) {return val < x;};

    auto sep = algo::partition(nums.begin(), nums.end(), pred );

    int ans1 = sep - nums.begin();
    int ans2 = nums.end() - sep;

    std::cout << ans1 << std::endl;
    std::cout << ans2 << std::endl;


    return EXIT_SUCCESS;
}