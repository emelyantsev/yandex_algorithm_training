#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <map>
#include <cassert>

class Splitter {

    public:

        Splitter(int max_len_, const std::vector<int>& colors_, const std::vector<int>& lens_, std::map<int, int>& split_counts_ ) 
                        : max_len( max_len_ ), colors(colors_) , lens(lens_) , dp(1, std::vector<int>(max_len+1, -1) ) , split_counts(split_counts_)
        {
            dp[0][0] = 0;
            
            for (int i = 0; i < colors.size(); ++i) {

                dp.push_back( dp.back() );

                int len = lens[ colors[i] ] ;
                int ind = colors[i] + 1;

                for (int j = max_len - len; j >= 0; --j) {

                    if ( dp.back()[j] != -1 && dp.back()[j+len] == -1 ) {

                        dp.back()[j+len] = ind;
                        split_start[j+len] = dp.size() - 1;
                        split_counts[j+len] += 1;
                    }
                }
            }
            
            dp.clear();
        }

        std::vector<int> GetSplit(int len) const {

            dp.resize( 1, std::vector<int>(max_len+1, -1) ) ;

            dp[0][0] = 0;
            
            for (int i = 0; i < colors.size(); ++i) {

                dp.push_back( dp.back() );

                int len = lens[ colors[i] ] ;
                int ind = colors[i] + 1;

                for (int j = max_len - len; j >= 0; --j) {

                    if ( dp.back()[j] != -1 && dp.back()[j+len] == -1 ) {

                        dp.back()[j+len] = ind;
                    }
                }
            }


            std::vector<int> ans;

            const std::vector<int>& dpi = dp[ split_start.at(len) ] ;

            int curr = dpi[len];

            while (curr != 0) {

                ans.push_back(curr) ;

                len -= lens[curr - 1];
                curr = dpi[ len ];
            }

            dp.clear();

            return ans;
        }

    private:

        int max_len;
        const std::vector<int>& colors;
        const std::vector<int>& lens;

        mutable std::vector<std::vector<int>> dp;
        std::unordered_map<int, int> split_start;
        std::map<int, int>& split_counts;
};


int main() {

    int n, k;

    std::cin >> n >> k;

    std::vector<int> len(n);
    std::vector< std::vector<int> > color(k);

    int l1 = 0;

    for (int i = 0; i < n; ++i) {

        std::cin >> len[i];

        int c;
        std::cin >> c;

        if (c == 1) {
            l1 += len[i] ;
        }

        color[c-1].push_back(i);
    }


    std::vector<Splitter> splitters;

    std::map<int, int> split_counts;

    for (const std::vector<int>& ci : color) {

        if ( ci.size() == 1 ) {

            std::cout << "NO" << std::endl;
            return EXIT_SUCCESS;
        }

        splitters.emplace_back( l1, ci, len, split_counts);
    }

    std::vector<int> ans;

    for (const auto& [l, count] : split_counts ) {

        if (count == k && l != l1) {

            for (const Splitter& spl : splitters) {

                std::vector<int> indexes = spl.GetSplit(l);

                assert( !indexes.empty() ) ;

                ans.insert( ans.end(), indexes.begin(), indexes.end() ) ;
            }

            break;
        }

    }

    if (ans.size() == 0) {

        std::cout << "NO" << std::endl;
    }
    else {

        std::cout << "YES" << std::endl;

        for (int ai : ans) {

            std::cout << ai << " ";
        }

        std::cout << std::endl;
    }
    

    return EXIT_SUCCESS;
}