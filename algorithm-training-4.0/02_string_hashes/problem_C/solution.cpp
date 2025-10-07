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

        long long Hash(int from, int len) {

            return ( h[from + len - 1] - h[from - 1] * px[len] % mod + mod ) % mod;
        }

        bool IsEqual(int from1, int from2, int len ) {

            assert( from1 > 0 && from1 <= size() ) ;
            assert( from2 > 0 && from2 <= size() ) ;

            return Hash(from1, len) == Hash(from2, len);
        }

        int GetZ(int from) {

            if (from == 1) {
                return 0;
            }
            
            int l = 1;
            int r = size() - from + 1;

            while (true) {

                int mid = (r+l) / 2;

                if ( IsEqual(1, from, mid) ) {

                    if (mid == size() - from + 1 ) {
                        return mid;
                    }

                    if (!IsEqual(1, from, mid + 1) ) {
                        return mid;
                    }
                    
                    l = mid + 1;
                }
                else {

                    if (mid == 1) {
                        return 0;
                    }
                    else {
                        r = mid - 1;
                    }
                }
            }
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

    HashedString hs(s);
   
    for (int i = 1; i <= hs.size() ; ++i) {


        std::cout << hs.GetZ(i) << " ";
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}