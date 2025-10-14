#include <iostream>
#include <map>
#include <climits>
#include <cassert>
#include <vector>
#include <algorithm>

class Window {

    public:

        void Add(int val) {
            
            numCounts[val] += 1;
            totalSum += val;
            min = numCounts.begin()->first;
        }

        void Remove(int val) {

            numCounts.at(val) -= 1;
            if (numCounts.at(val)  == 0) {
                numCounts.erase(val);
            }
            totalSum -= val;

            assert(totalSum >= 0);
            min = numCounts.begin()->first;
        }

        int GetScore() {
            return totalSum * min;
        }

    private:

        std::map<int, int> numCounts;
        int totalSum = 0;
        int min = INT_MAX;

};


int main() {


    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {

        std::cin >> a[i];
    }

    Window w;

    for (int i = 0; i < k; ++i) {
        w.Add(a[i]);
    }

    std::vector<int> dp;
    dp.push_back(w.GetScore());

    for (int i = k; i < n; ++i) {

        w.Add( a[i] );
        w.Remove( a[i-k] );

        if ( dp.size() < k ) {

            dp.push_back( std::max(dp.back(), w.GetScore() ) );
        }
        else {            
            dp.push_back( std::max(dp.back(), dp[dp.size()-k] + w.GetScore() ) );
        }


    }

    int i = dp.size() - 1;

    std::vector<int> res;

    while (true) {

        if (i > 0 ) {

            if (dp[i] > dp[i-1]) {
                res.push_back(i+1);
                i -= k;
            }
            else {
                --i;
            }
        }
        else if (i == 0) {
            res.push_back(i+1);
            break;
        }
        else {
            break;
        }
    }

    std::cout << res.size() << std::endl;

    for (auto it = res.rbegin(); it != res.rend(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;


    return 0;
}