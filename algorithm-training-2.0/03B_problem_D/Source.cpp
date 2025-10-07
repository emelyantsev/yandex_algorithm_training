#include <string>
#include <iostream>
#include <set>
#include <sstream>
#include <utility>

int main() {

	std::string input;

	std::getline( std::cin, input );

	std::istringstream stream(input);

	int n;
	stream >> n;

	std::set<int> pos_nums;

	for (int i = 1; i <= n; ++i) {
		
		pos_nums.insert(i);
	}
	

	std::getline(std::cin, input);

	while (input != "HELP") {

		std::istringstream stream(input);

		std::set<int> nums;

		int num;

		while (stream >> num) {
			nums.insert(num);
		}

		std::string status;
		std::getline(std::cin, status);

		if (status == "YES") {

			std::set<int> new_pos_nums;

			if (nums.size() < pos_nums.size()) {

				for (int num : nums) {

					if (pos_nums.count(num) == 1) {
						new_pos_nums.insert(num);
					}
				}
			}
			else {

				for (int num : pos_nums) {

					if (nums.count(num) == 1) {
						new_pos_nums.insert(num);
					}
				}
			}


			pos_nums = std::move(new_pos_nums);
		}
		else {

			for (int num : nums) {

				pos_nums.erase(num);
			}
		}


		std::getline(std::cin, input);

		}




	for (int num : pos_nums) {

		std::cout << num << " ";
	}

	std::cout << std::endl;


	return 0;
}