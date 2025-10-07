#include <iostream>
#include <algorithm>
#include <vector>

bool check_placing(const std::vector<int>& rows) {

    const int n = rows.size();

    for (int i = 1; i < rows.size(); ++i) {

        for (int j = 0; j < i; ++j) {

            int r1 = rows[i];
            int c1 = i;
            int r2 = rows[j];
            int c2 = j;  

            int dl1 = r1+c1;
            int dl2 = r2+c2;

            if (dl1 == dl2 ) {
                return false;
            }

            int dr1 = r1 + (n - c1 + 1);
            int dr2 = r2 + (n - c2 + 1);  

            if (dr1 == dr2 ) {
                return false;
            }
        }
    }

    return true;
}


int main() {

    int N;
    std::cin >> N;

    std::vector<int> rows(N);

    for (int i = 0; i < N; ++i) {
        rows[i] = i;
    }

    int ans = 0;

    do {

        bool is_good = check_placing(rows);

        ans += is_good ? 1 : 0;

    } while (std::next_permutation( rows.begin(), rows.end() ) );

    std::cout << ans << std::endl;

    return 0;
}