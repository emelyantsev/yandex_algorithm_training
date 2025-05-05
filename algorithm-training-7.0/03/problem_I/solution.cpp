#include <iostream>
#include <string>
#include <cstdlib>

bool isPow2(int num) {

    if (num == 0) {
        return false;
    }

    for (int i = 0; i < 32; ++i) {

        if (num == (1 << i)) {
            return true;
        }
    }
    
    return false;
}


std::string encode(const std::string& input) {

    std::string res;

    for (char c : input) {

        while( isPow2( res.size() + 1 ) ) {
            res.push_back( '0' );
        }
        res.push_back( c );
    
    }

    for (int i = 0; i < 32; ++i) {

        int ind = 1 << i;

        if (ind > res.size() ) {
            break;
        }

        int sum = 0;

        for (int j = ind + 1; j <= res.size(); ++j) {

            if ( ( j & ind) != 0 ) {
                sum += res[j-1] - '0';
            }
        }

        if (sum % 2 == 0) {
            res[ind-1] = '1';
        }

    }


    return res;
}


std::string decode(std::string& input) {


    int res_ind = 0;; 

    for (int i = 0; i < 32; ++i) {

        int ind = 1 << i;

        if (ind > input.size() ) {
            break;
        }

        int sum = 0;

        for (int j = ind; j <= input.size(); ++j) {

            if ( ( j & ind) != 0 ) {
                sum += input[j-1] - '0';
            }
        }

        if (sum % 2 == 0) {
            res_ind |= 1 << i;
        }

    }

    if (res_ind != 0) {
        input[res_ind - 1] = input[res_ind - 1] == '1' ? '0' : '1';
    }

    std::string result;

    for (int i = 0; i < input.size(); ++i) {

        if (!isPow2(i+1)) {
            result.push_back(input[i]) ;
        }
    }


    return result;
}


int main() {

    
    int type;

    std::cin >> type;

    std::string val;

    std::cin >> val;

    if (type == 1) {

        std::cout << encode( val ) << std::endl;
    }
    else {

        std::cout << decode( val ) << std::endl;
    }



    return 0;
}