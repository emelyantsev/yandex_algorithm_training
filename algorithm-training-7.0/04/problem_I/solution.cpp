#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>
#include <utility>


class Cloner {

    public:

        struct Node {
            Node* prev;
            long long val;
        };

        Cloner() : m(1,0), ptr(1, nullptr), total(0) {}

        void ClonePush(long long val, int ver) {

            nodes.emplace_back( new Node{ ptr[ver], val } );
            ptr.push_back(nodes.back().get() ) ;

            long long new_m = m[ver] + val ;
            m.push_back( new_m );
            total += new_m;
        }

        void ClonePop(int ver) {

            ptr.push_back( ptr[ver]->prev  );
            long long new_m = m[ver] - ptr[ver]->val ;
            m.push_back(new_m);
            total += new_m;
        }

        long long GetTotal() {
            return total;
        }

    private:

        std::vector<std::unique_ptr<Node>> nodes;
        std::vector<long long> m;
        std::vector<Node*> ptr;
        long long total;
};



int main() {

    Cloner cloner;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {

        int t;
        long long m;
        std::cin >> t >> m;

        if (m == 0) {
            cloner.ClonePop(t);
        }
        else {
            cloner.ClonePush(m, t);
        }
    }

    std::cout << cloner.GetTotal() << std::endl;


    return EXIT_SUCCESS;
}