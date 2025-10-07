#include <iostream>
#include <map>
#include <string>
#include <sstream>


int main() {


	std::map<std::string, std::map<std::string, long long> > db;

	std::string line;
	
	while (std::getline(std::cin, line)) {

		std::istringstream s(line) ;

		std::string name;
		std::string item;
		long long count;
		s >> name >> item >> count;

		db[name][item] += count;

	}


	for (const auto& [name, items_count] : db) {

		std::cout << name << ":\n";

		for (const auto& [item, count] : items_count) {

			std::cout << item << " " << count << std::endl;
		}


	}



}