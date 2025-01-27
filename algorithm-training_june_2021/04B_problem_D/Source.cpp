#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <algorithm>

struct Item {

	long long rem;
	long long count;
	std::string name;

	friend bool operator<(const Item& l, const Item& r) {

		return std::tie(l.rem, l.count) > std::tie(r.rem, r.count);
	}

};

int main() {

	std::vector<std::string> names;

	std::unordered_map<std::string, long long> counts;

	std::string line;

	long long total_count = 0;

	while (std::getline(std::cin, line)) {

		int split_index = line.find_last_of(' ');

		std::string name = line.substr(0, split_index);

		std::string str_count = line.substr(split_index + 1);

		long long count = std::stoll(str_count);

		total_count += count;

		counts[name] = count;
		names.push_back(name);
	}

	std::unordered_map<std::string, long long> seat_counts;

	std::vector<Item> items;

	long long total_seat_count = 0;

	for (const auto& [name, count] : counts) {

		long long seat_count = count * 450 / total_count;
		long long rem = count * 450 % total_count;

		seat_counts[name] = seat_count;

		items.push_back({ rem, count, name });

		total_seat_count += seat_count;
	}

	std::sort(items.begin(), items.end());

	long long rem_seats = 450 - total_seat_count;

	for (int i = 0; i < rem_seats; ++i) {

		++seat_counts[items[i].name];
	}


	for (const std::string& name : names) {

		std::cout << name << " " << seat_counts[name] << std::endl;
	}

}