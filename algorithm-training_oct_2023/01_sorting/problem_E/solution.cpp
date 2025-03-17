#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <utility>

class Sorter {

    public:

        void ReadInput() {

            std::cin >> n;

            nums.resize(n);

            for (int i = 0; i < n; ++i) {
                std::cin >> nums[i];
            }
        }

        void PrintInitial() {

            std::cout << "Initial array:\n";

            bool first = true;

            for (const std::string& num : nums) {

                if (first) {
                    std::cout << num;
                    first = false;
                }
                else {

                    std::cout << ", " << num;
                }
            }

            std::cout << std::endl;
        }

        void Sort() {

            int steps = nums.front().size();

            for (int i = 0; i < steps; ++i) {

                std::vector< std::vector<std::string> > buckets(10);

                for (int j = 0; j < n; ++j) {

                    int bucket_num = nums[j][steps - i - 1] - '0';
                    buckets[bucket_num].push_back(std::move(nums[j]) ) ;
                }

                std::cout << "**********\n";

                std::cout << "Phase " << i + 1 << std::endl;

                for (int k = 0; k < 10; ++k) {

                    std::cout << "Bucket " << k << ": ";

                    bool first = true;

                    if (buckets[k].size() == 0) {
                        std::cout << "empty\n";
                        continue;
                    }

                    for (const std::string& item : buckets[k]) {

                        if (first) {
                            std::cout << item;
                            first = false;
                        }
                        else {
                            std::cout << ", " << item;
                        }
                    }

                    std::cout << std::endl;
                }

                nums.clear();

                for (int k = 0; k < 10; ++k) {

                    for ( std::string& num : buckets[k] ) {

                        nums.push_back( std::move(num) );
                    }
                }
            }
        }

        void PrintSorted() {

            std::cout << "**********\nSorted array:\n" ;

            bool first = true;

            for (const std::string& num : nums) {

                if (first) {
                    std::cout << num;
                    first = false;
                }
                else {

                    std::cout << ", " << num;
                }
            }
            
            std::cout << std::endl;
        }


    private:

        int n;
        std::vector<std::string> nums;


};


int main() {

    Sorter sorter;

    sorter.ReadInput();
    sorter.PrintInitial();
    sorter.Sort();
    sorter.PrintSorted();


    return EXIT_SUCCESS;
}