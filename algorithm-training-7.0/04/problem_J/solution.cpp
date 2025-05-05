#include <list>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <cassert>

class RiverManager {

    public:

        RiverManager( const std::vector<long long>& nums) : total_sum(0) {

            for (auto num : nums) {
                items.push_back(num);
                total_sum += num * num;
                
            }

            cur_it = items.begin();
            cur_index = 1;
        }

        long long GetTotal() {

            return total_sum;
        }

        void Bankrupt(int ind) {

            assert(items.size() > 1);

            if (ind == 1) {

                auto it = items.begin();

                long long val = *it;
                auto next_it = std::next( it );
                long long next_val = *next_it;

                total_sum = total_sum - (val*val) - (next_val*next_val) + (next_val+val)*(next_val+val);
                items.erase(it);
                *next_it += val;
                cur_it = items.begin();
                cur_index = 1;
            }
            else if ( ind == items.size() ) {

                auto it = std::prev( items.end() );

                long long val = *it;
                auto prev_it = std::prev( it );
                long long prev_val = *prev_it;

                total_sum = total_sum - (val*val) - (prev_val*prev_val) + (prev_val+val)*(prev_val+val);
                items.erase(it);
                *prev_it += val;
                cur_it = prev_it;
                cur_index = items.size();
            }
            else {

                auto it = std::next( cur_it, ind - cur_index );


                long long val = *it;

                auto prev_it = std::prev( it );
                long long prev_val = *prev_it;

                auto next_it = std::next( it ) ;
                long long next_val = *next_it;

                long long lv = val / 2 ;
                long long rv = val / 2 + val % 2;


                total_sum += - (val*val) - (prev_val*prev_val) - (next_val*next_val) + (prev_val+lv)*(prev_val+lv) + (next_val + rv)*(next_val+rv);
                items.erase(it);
                *prev_it += lv;
                *next_it += rv;
                cur_it = prev_it;
                cur_index = ind - 1;
            }

        }

        void Split(int ind) {

            auto it = std::next( cur_it, ind - cur_index );
            long long val = *it;

            long long lv = val / 2 ;
            long long rv = val / 2 + val % 2;

            total_sum += - val * val + lv * lv + rv * rv;

            *it = lv;

            items.insert(std::next(it), rv);

            cur_it = it;
            cur_index = ind;
        }


    private:

        std::list<long long> items;
        long long total_sum;
        std::list<long long>::iterator cur_it;
        int cur_index;
};



int main() {

    int n;
    std::cin >> n;

    std::vector<long long> a(n);

    for (int i = 0; i < n; ++i) {

        std::cin >> a[i];
    }

    RiverManager mng(a);

    std::cout << mng.GetTotal() << std::endl;

    int k;
    std::cin >> k;

    for (int i = 0; i < k; ++i) {

        int type, ind;
        std::cin >> type >> ind;

        if (type == 1) {
            mng.Bankrupt(ind);
        }
        else {
            mng.Split(ind);
        }

        std::cout << mng.GetTotal() << std::endl;
    }

    return EXIT_SUCCESS;
}