#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <vector>

class HashedString : public std::string {

    public :

        HashedString(const std::string& source, long long x_ = 257, long long mod_ = 1000000007) : std::string(source), x(x_), mod(mod_) {

            int n = size() + 1;
            px.reserve(n);
            px.push_back(1);

            for (int i = 0; i < n - 1; ++i) {

                px.push_back( ( px.back() * x) % mod );
            }

            h.reserve(n);
            h.push_back(0);

            for (int i = 0; i < n - 1; ++i) {

                h.push_back(  ( h.back() * x + std::string::operator[](i) ) % mod  ) ;
            }
        }

        bool IsEqual(int from1, int from2, int len ) {

            assert( from1 > 0 && from1 <= size() ) ;
            assert( from2 > 0 && from2 <= size() ) ;

            return ( h[from1 + len - 1] + h[from2 - 1] * px[len] ) % mod == ( h[from2 + len - 1] + h[from1 - 1] * px[len] ) % mod ;
        }

    private:

        long long x;
        long long mod;

        std::vector<long long> px;
        std::vector<long long> h;

};


int main() {

    std::string s;
    std::cin >> s;

    int q;
    std::cin >> q;

    HashedString hs(s);

    for (int i = 0 ; i < q; ++i) {

        int L, A, B;

        std::cin >> L >> A >> B;
        ++A; ++B;

        std::cout << ( hs.IsEqual(A, B, L) ? "yes" : "no" ) << std::endl;

    }

    return EXIT_SUCCESS;
}