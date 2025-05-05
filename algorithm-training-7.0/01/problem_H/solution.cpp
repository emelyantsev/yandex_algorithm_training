#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

struct Item {
    int ind;
    int even_count;
    int odd_count;
};


int main() {

    int n;

    std::cin >> n;

    std::vector< std::string> strings(n);
  
    std::vector<Item> odd_items;
    std::vector<Item> even_items;

    for (int i = 0; i < n; ++i) {

        std::cin >> strings[i];

        Item item{i,0,0};

        for (int j = 0; j < strings[i].size() ; ++j) {

            if (j % 2 == 0 && strings[i][j] == 'S' ) {
                ++item.even_count;
            }
            else if ( j % 2 == 1 && strings[i][j] == 'S' ) {
                ++item.odd_count ;
            }
        }

        if (strings[i].size() % 2 == 0 ) {

            even_items.push_back(item);
        }
        else {
            odd_items.push_back(item);
        }
    }

    std::sort(even_items.begin(), even_items.end(), [](const Item& l, const Item& r){ return l.even_count - l.odd_count > r.even_count - r.odd_count ; } ) ;

    std::sort(odd_items.begin(), odd_items.end(), [](const Item& l, const Item& r){ return l.even_count - l.odd_count > r.even_count - r.odd_count ; } ) ;

    int ans = 0;
    
    if ( odd_items.size() == 0) {

        for (const Item& item : even_items ) {
            ans += item.even_count;
        }
    }

    else {

        for (const Item& item : even_items ) {
            ans += std::max( item.even_count, item.odd_count );
        }

        int i = 0;
        int j = odd_items.size() - 1;


        while (true) {

            ans += odd_items[i].even_count;

            if (j != i) {                
                ans += odd_items[j].odd_count;
            }
            else {
                break;
            }

            ++i;
            --j;

            if (i > j) {
                break;
            }

        }


    }

    std::cout << ans << std::endl;

    return EXIT_SUCCESS;
}