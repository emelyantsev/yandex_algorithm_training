#include <list>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>

class Game {

    struct Item {
        int ind;
        int rate;
    };


    public:

        Game( const std::vector<int>&  r) : ans( r.size(), 0 ), min_r( r.size(), 0 ) {

            for (int i = 0; i < r.size(); ++i) {

                items.emplace_back(i, r[i]);
            }
        }

        void Play() {

            auto curr = items.begin();

            //int curr_round = 1;

            while (true) {

                if ( canRemove(curr) ) {
                    curr = remove(curr, 1);
                }

                ++curr;

                if (curr == items.end()) {
                    break;
                }

            }

        }

        const std::vector<int>& GetAns() {
            return ans;
        }

    private:

        std::list<Item>::iterator prev( const std::list<Item>::iterator& curr ) {

            if (curr == items.begin() ) {

                return std::prev(items.end() ) ;
            }
            else {
                return std::prev(curr);
            }
        }

        std::list<Item>::iterator next( const std::list<Item>::iterator& curr ) {

            if (curr == std::prev( items.end() )  ) {
                return items.begin() ;
            }
            else {
                return std::next(curr);
            }
        }

        bool canRemove( const std::list<Item>::iterator& curr ) {

            if (items.size() == 2) {
                return false;
            }

            auto prev_it = prev(curr);
            auto next_it = next(curr);

            if ( curr->rate < prev_it->rate && curr->rate < next_it->rate ) {

               return true;
            }
            else {
                return false;
            }

        }

        std::list<Item>::iterator remove(std::list<Item>::iterator it, int round) {

            round = std::max(round, min_r[it->ind]);

            ans[it->ind] = round; 

            auto pr_it = prev(it);
            auto next_it = next(it);

            min_r[pr_it->ind] = std::max(min_r[pr_it->ind], round+1);
            min_r[next_it->ind] = std::max(min_r[next_it->ind],  round+1);

            it = items.erase(it);

            if (it == items.end() ) {
                it = items.begin();
            }

            auto prev_it = prev(it);

            if (  canRemove( prev_it ) ) {
                return remove( prev_it, round+1 );
            }
            else if ( canRemove(it) ) {
                return remove(it, round+1);
            }
            else {
                return it;
            }
        }


        std::vector<int> ans;
        std::vector<int> min_r;
        std::list<Item> items;

};


int main() {

    int n;
    std::cin >> n;

    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {

        std::cin >> a[i];
    }

    Game game(a);

    game.Play();

    auto& ans = game.GetAns();

    for (int ai : ans) {
        std::cout << ai << " ";
    }
    std::cout << std::endl;


    return EXIT_SUCCESS;
}