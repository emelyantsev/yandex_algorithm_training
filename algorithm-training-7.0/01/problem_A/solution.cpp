#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

int main() {

    int n, m;
    std::cin >> n >> m;

    std::vector<int> x(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }
    
    std::vector<int> y(m);

    for (int i = 0; i < m; ++i) {

        std::cin >> y[i];
    }

    std::vector<int> xi;
    xi.reserve(n);
    for (int i = 0; i < n; ++i) {
        xi.push_back(i);
    }


    std::vector<int> yi;
    yi.reserve(m);
    for (int i = 0; i < m; ++i) {
        yi.push_back(i);
    }

    std::stable_sort(xi.begin(), xi.end(), [&x](int l, int r) {return x[l] < x[r] ; } ) ;

    std::stable_sort(yi.begin(), yi.end(), [&y](int l, int r) {return y[l] < y[r] ; } ) ;


    std::vector<int> ans(n, 0);
    int count = 0;


    int j = 0;

    for (int i = 0; i < n; ++i) {

        while (j < m && x[xi[i]] + 1 > y[yi[j]] ) {
            ++j;
        }

        if (j < m) {
            ans[xi[i]] = yi[j] + 1;
            ++j;
            ++count;
        }
        else {
            break;
        }
    }

    std::cout << count << std::endl;

    for (int elem : ans) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

