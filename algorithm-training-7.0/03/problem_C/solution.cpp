#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cassert>

int count_ones(long long n) {

    int res = 0;
    while (n != 0) {

        if (n % 2 == 1) {
            ++res;
        }
        n /= 2;
    }

    return res;
}

int find_pos_zero(const std::string& str) {

    int p1 = -1;

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '1') {
            p1 = i;
        }
    }


    return  (p1 == str.size() - 1) ? p1 : ( p1 + 1 );

}

int calc_max_len(long long num) {

    int res = 0;
    while (num != 0) {

        ++res;
        num /= 2;
    }

    return res;
}

void print_ans(const std::vector<std::string>& ans) {
    for (const auto& s : ans) {
        std::cout << s << std::endl;
    }
    std::cout << std::endl;
}


int main() {


    int n;
    std::cin >> n;

    long long max_len = 0;
    int sum_ones = 0;

    std::vector<int> a(n, 0);
    std::map<int, std::set<int> > curr_counts;

    for (int i = 0; i < n; ++i) {

        long long ai;
        std::cin >> ai;
        int c1 = count_ones(ai);

        a[i] = c1;

        sum_ones += c1;
        max_len = std::max(max_len, ai);
        
        curr_counts[c1].insert(i);
    }

    max_len = calc_max_len(max_len);

    if (sum_ones % 2 == 1) {
        std::cout << "impossible" << std::endl;
        return 0;
    }

    if (n % 2 == 1  && sum_ones > (n-1)*max_len ) {
        std::cout << "impossible" << std::endl;
        return 0;
    } 

    std::vector<std::string> ans(n, std::string(max_len, '0'));

    while (true) {

       print_ans(ans);

        if (curr_counts.size() == 0) {
            break;
        }

        auto it1 = std::prev( curr_counts.end() );

        int c1 = it1->first;

        if (c1 == 0) {
            break;
        }

        int i1 = *it1->second.begin();

        curr_counts[c1].erase(i1);

        if ( curr_counts[c1].size() == 0) {
            curr_counts.erase(c1);
        }

        if (curr_counts.size() == 0) {
            break;
        }

        auto it2 = std::prev( curr_counts.end() );

        int c2 = it2->first;

        if (c2 == 0) {
            break;
        }

        int i2 = *it2->second.begin();

        curr_counts[c2].erase(i2);

        if ( curr_counts[c2].size() == 0) {
            curr_counts.erase(c2);
        }


        if (c1 > 1) {

            curr_counts[c1-1].insert(i1);
        }

        if (c2 > 1) {

            curr_counts[c2-1].insert(i2);
        }

        int z1 = find_pos_zero(ans[i1]);
        int z2 = find_pos_zero(ans[i2]);

        int zi = std::max(z1, z2);

        ans[i1][zi] = '1';
        ans[i2][zi] = '1';

    }

    for (const std::string& str : ans) {
        std::cout << std::stoll(str, nullptr, 2) << " ";
    }

    std::cout << std::endl;


    return 0;
}