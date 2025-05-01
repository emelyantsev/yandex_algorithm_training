#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

class SumArray {

    public:

        SumArray(int n) : sums(n, 0), nums(n, 0) {}

        void Set(int ind, long long val) {

            long long d = val - nums[ind];

            if (d == 0) {
                return;
            }
            
            nums[ind] = val;

            int j = ind;

            while (j < sums.size() ) {

                sums[j] += d;
                j |= j + 1;
            }


        }

        long long GetSum(int from, int to) {

            if (from == 0) {
                return getSum(to);
            }
            else {

                return getSum(to) - getSum(from-1);
            }
        }

        long long getSum(int to) {

            if (to == 0) {
                return sums[0];
            }

            long long res = 0;
            int i = to;

            while (i >= 0) {

                res += sums[i];
                i = f(i) - 1;
            }

           return res;     
        }

        int f(int i) {
            return i & (i+1);
        }

    private:


        std::vector<long long> sums;
        std::vector<long long> nums;
};


int main() {

    int n, k;
    std::cin >> n >> k;

    SumArray arr(n);

    for (int i = 0; i < k; ++i) {

        std::string type;
        std::cin >> type;

        if (type == "A") {

            int ind;
            long long val;

            std::cin >> ind >> val;
            arr.Set(ind-1, val);
        }
        else {

            int from, to;
            std::cin >> from >> to;
            std::cout << arr.GetSum(from-1, to-1) << std::endl;
        }
        
    }



    return EXIT_SUCCESS;
}