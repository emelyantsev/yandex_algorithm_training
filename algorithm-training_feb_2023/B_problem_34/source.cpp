#include <iostream>
#include <vector>
#include <queue>

int main() {

    int N, M;
    std::cin >> N >> M;

    std::vector< std::vector<int> > g(N);
    std::vector<int> counts(N, 0);

    for (int i = 0; i < M; ++i) {

        int a, b;
        std::cin >> a >> b;
        --a; --b;

        g[a].push_back(b);
        ++counts[b]; 
    }

    std::queue<int> q;

    std::vector<int> ans;
    ans.reserve(N);

    

    for ( int i = 0; i < N; ++i) {

        if ( counts[i] == 0) {
            q.push(i);
        }

    }

    while ( !q.empty() ) {

        int curr = q.front();
        q.pop();

        for (int to : g[curr]) {

            --counts[to];
            if (counts[to] == 0) {
                q.push(to);
            }
        }

        ans.push_back(curr);
    }

    if (ans.size() != N) {
        std::cout << -1 << std::endl;
    }
    else {

        for (int ai : ans) {

            std::cout << (ai + 1) << " ";
        }
        std::cout << std::endl;

    }

    return 0;
}