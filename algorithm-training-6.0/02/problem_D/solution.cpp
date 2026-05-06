#include <iostream>
#include <set>


int main() {

    int n, k;
    std::cin >> n >> k;

    std::multiset<int> numbers;

    for (int i = 0; i < n; ++i) {

        int a;
        std::cin >> a;

        numbers.insert(a);
    }

    int ans = 0;

    while (!numbers.empty()) {

        ++ans;

        int curr = *numbers.begin();

        numbers.erase(numbers.begin() );

        auto it = numbers.upper_bound(curr+k);

        while (it != numbers.end() ) {

            curr = *it;
            numbers.erase(*it);

            it = numbers.upper_bound(curr+k);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}