#include <iostream>
#include <tuple>
#include <set>
#include <vector>


using Item = std::tuple<int, int, int>;


struct Compare {

    bool operator()(const Item& a, const Item& b) const {
                
        return std::get<0>(a) > std::get<0>(b) ||  (std::get<0>(a) == std::get<0>(b) &&  std::get<1>(a) > std::get<1>(b) ) || 
        (std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) < std::get<2>(b) )
        ;
    }
};


int main() {

    int n;
    std::cin >> n;

    std::vector<int> a, b;

    for (int i = 0; i < n; ++i) {

        int temp;
        std::cin >> temp;

        a.push_back(temp);
    }

    for (int i = 0; i < n; ++i) {

        int temp;
        std::cin >> temp;

        b.push_back(temp);
    }

    std::set< Item, Compare> as, bs;

    for (int i = 0; i < n; ++i) {

        as.insert({a[i], b[i], i} );
        bs.insert( {b[i], a[i], i} );
    }

    std::vector<int> res;

    for (int i = 0; i < n; ++i) {

        int val;
        std::cin >> val;

        if (val == 1) {

            Item item = *bs.begin();
            bs.erase(item);

            as.erase( {std::get<1>(item), std::get<0>(item), std::get<2>(item)  }  ) ;
            
            res.push_back( std::get<2>(item)+1 );
        }
        else {

            Item item = *as.begin();
            as.erase(item);

            bs.erase( {std::get<1>(item), std::get<0>(item), std::get<2>(item)  }  ) ;
            
            res.push_back( std::get<2>(item)+1 );
        }
    }

    for (const auto& val : res) {
        std::cout << val << " ";
    }

    std::cout << std::endl;



    return 0;

}