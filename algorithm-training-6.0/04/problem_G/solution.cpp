#include <iostream>
#include <vector>
#include <stdexcept>

class Solution {

    public:

        Solution(int n, int k) : n(n), MOD(k), graph(n+1), ans(1), lonely_cnt(0), trees_cnt(0), visited(n+1, false)  {

            factorial.push_back(1);

            for (int i = 1; i < n+1; ++i) {

                int new_val = ( static_cast<long long>( factorial.back() ) * i ) % MOD;
                factorial.push_back( new_val ); 
            }
        }

        void AddPair(int a, int b) {

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        void Process() {

            for (int i = 1; i <= n; ++i) {

                if ( !visited[i] && graph[i].size() > 0  ) {

                    ++trees_cnt;

                    try {
                        visit_and_process(i, -1);
                    }
                    catch (const std::exception& e) {
                        ans = 0;
                        return;
                    }

                }

                if ( graph[i].size() == 0) {
                    ++lonely_cnt;
                }
            }

            ans = ( static_cast<long long>( ans ) * factorial[trees_cnt] ) % MOD;

            int not_lonely = n - lonely_cnt;

            for (int i = 0; i < lonely_cnt; ++i) {

                ans = ( static_cast<long long>( ans ) * (2 + not_lonely + i) ) % MOD;
            }
        }

        int GetAns() { return ans; }

    private:


        int visit_and_process(int v, int parent) {

            bool is_root = parent == -1;

            if (is_root && graph[v].size() == 1 && graph[graph[v][0]].size() > 1) {
                return visit_and_process( graph[v][0], -1 ) ;
            }

            visited[v] = true;
            int big_child_cnt = 0;
            int subtree_size = 1;

            for (int child : graph[v] ) {

                if (visited[child] && child != parent) {
                    throw std::logic_error("cycled dependency");
                }

                else if (!visited[child]) {

                    int curr_size = visit_and_process(child, v);
                    subtree_size += curr_size;

                    if (curr_size >= 2) {

                        big_child_cnt += 1;
                    }

                    if (  ( is_root && big_child_cnt > 2 ) || (!is_root && big_child_cnt > 1) ) {

                        throw std::logic_error("too many big childs");
                    }
                }
            }

            int small_child_cnt = graph[v].size() - (is_root ? 0 : 1) - big_child_cnt  ;
            ans = (static_cast<long long>( ans ) * factorial[small_child_cnt] ) % MOD;

            if (is_root) {

                ans = (static_cast<long long>( ans ) * 2 ) % MOD;

                if (small_child_cnt > 0 && big_child_cnt > 0 || big_child_cnt == 2 ) {

                    ans = (static_cast<long long>( ans ) * 2 ) % MOD;
                }
            }

            return subtree_size;
        }



        int n;
        int MOD;
        std::vector<int> factorial;
        std::vector<std::vector<int> > graph;
        int ans;
        int lonely_cnt;
        int trees_cnt;
        std::vector<bool> visited;
};




int main() {


    int N, M, K;
    std::cin >> N >> M >> K;

    if ( M > N - 1 ) {
        std::cout << 0 << std::endl;
        return 0;
    }

    Solution sln(N, K);

    for (int i = 0; i < M; ++i) {

        int a, b;
        std::cin >> a >> b;

        sln.AddPair(a, b);
    }

    sln.Process();

    int ans = sln.GetAns();
    std::cout << ans << std::endl;

    return 0;
}