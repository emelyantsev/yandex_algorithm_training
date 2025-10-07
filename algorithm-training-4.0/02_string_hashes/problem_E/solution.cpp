#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <algorithm>

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

        long long Hash(int from, int len) const {

            return ( h[from + len - 1] - h[from - 1] * px[len] % mod + mod ) % mod;
        }

        bool IsEqual(int from1, int from2, int len ) {

            assert( from1 > 0 && from1 <= size() ) ;
            assert( from2 > 0 && from2 <= size() ) ;

            return Hash(from1, len) == Hash(from2, len);
        }

        static int GetOddPalCount(const HashedString& orig, const HashedString& reversed, int from) {

            int max_len = std::min( (int) orig.size() - from , from - 1);
            
            int l = 0;
            int r = max_len;

            long long count = 0;

            while (true) {

                int mid = (r+l) / 2;

                if ( mid == 0 || orig.Hash(from+1, mid) == reversed.Hash( reversed.size() - from + 2, mid  )  ) {

                    if ( mid == max_len ) {
                        count += mid;
                        break;
                    }

                    if ( orig.Hash(from+1, mid+1) != reversed.Hash( reversed.size() - from + 2, mid +1 ) ) {
                        count += mid;
                        break;
                    }
                    
                    l = mid + 1;
                }
                else {

                    r = mid - 1;
                }
            }

            return count+1;
        }

        static int GetEvenPalCount(const HashedString& orig, const HashedString& reversed, int from) {

            int max_len = std::min( (int) orig.size() - from + 1, from - 1);
            
            int l = 0;
            int r = max_len;

            long long count = 0;

            while (true) {

                int mid = (r+l) / 2;

                if ( mid == 0 || orig.Hash(from, mid) == reversed.Hash( reversed.size() - from + 2, mid  )  ) {

                    if ( mid == max_len ) {
                        count += mid;
                        break;
                    }

                    if ( orig.Hash(from, mid+1) != reversed.Hash( reversed.size() - from + 2, mid +1 ) ) {
                        count += mid;
                        break;
                    }
                    
                    l = mid + 1;
                }
                else {

                    r = mid - 1;
                }
            }
            
            return count;
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

    std::reverse( s.begin(), s.end() ) ;

    HashedString rhs(s);
   
    long long count = 0;

    for (int i = 1; i <= hs.size(); ++i) {

        count += HashedString::GetOddPalCount( hs, rhs, i );
        count += HashedString::GetEvenPalCount( hs, rhs, i );
    }

    std::cout << count << std::endl;

    return EXIT_SUCCESS;
}