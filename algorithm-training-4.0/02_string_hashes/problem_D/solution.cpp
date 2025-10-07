#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <algorithm>

class HashedVector : public std::vector<long long> {

    public :

        HashedVector(const std::vector<long long>& source, long long x_ = 257, long long mod_ = 1000000007) : std::vector<long long>(source), x(x_), mod(mod_) {

            int n = size() + 1;
            px.reserve(n);
            px.push_back(1);

            for (int i = 0; i < n - 1; ++i) {

                px.push_back( ( px.back() * x) % mod );
            }

            h.reserve(n);
            h.push_back(0);

            for (int i = 0; i < n - 1; ++i) {

                h.push_back(  ( h.back() * x + std::vector<long long>::operator[](i) ) % mod  ) ;
            }
        }

        long long Hash(int from, int len) {

            return ( h[from + len - 1] - h[from - 1] * px[len] % mod + mod ) % mod;
        }

        bool IsEqual(int from1, int from2, int len ) {

            assert( from1 > 0 && from1 <= size() ) ;
            assert( from2 > 0 && from2 <= size() ) ;

            return Hash(from1, len) == Hash(from2, len);
        }

        

    private:

        long long x;
        long long mod;

        std::vector<long long> px;
        std::vector<long long> h;

};


int main() {

    int N;
    int M;

    std::cin >> N >> M;

    std::vector<long long> input(N);

    for (int i = 0; i < N; ++i) {

        std::cin >> input[i];
    }


    HashedVector hs(input, M+1);
   
    std::vector<long long> reversed_input(input);

    std::reverse( reversed_input.begin(), reversed_input.end() ) ;

    HashedVector reversed_hs(reversed_input, M+1);


    for (int i = hs.size() / 2 ; i > 0; --i) {

        int len = i;

        if ( hs.Hash(i+1, len) == reversed_hs.Hash( hs.size() - i + 1, len )  ) {
            std::cout << hs.size() - len << " ";
        }

    }

    std::cout << hs.size() << std::endl;

    return EXIT_SUCCESS;
}