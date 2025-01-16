#include <string>
#include <iostream>
#include <unordered_map>
#include <optional>
#include <sstream>


class Database {

public:

	Database() {};

	void Deposit(const std::string& name, int count) {
		db[name] += count;
	}

	void Withdraw(const std::string& name, int count) {
		db[name] -= count;
	}

	std::optional<int> Balance(const std::string& name) {
		if (db.count(name) == 1) {
			return db[name];
		}
		else {
			return std::nullopt;
		}
	}

	void Income(int p) {


		for (auto& [name, count] : db) {

			if (count > 0) {
				count += count * p / 100;
			}
		}

	}

	void Transfer(const std::string& from, const std::string& to, int count) {
		Withdraw(from, count);
		Deposit(to, count);
	}

private:

	std::unordered_map< std::string, int> db;

};




int main() {


	Database db;

	std::string line;

	while ( std::getline( std::cin, line ) ) {

		std::istringstream s(line);
		std::string command;
		s >> command;

		if (command == "DEPOSIT") {

			std::string name;
			int count;
			s >> name >> count;

			db.Deposit(name, count);
		}
		else if (command == "WITHDRAW") {

			std::string name;
			int count;
			s >> name >> count;
			db.Withdraw(name, count);
		}
		else if (command == "BALANCE") {

			std::string name;
			s >> name;

			auto balance = db.Balance(name);

			if (balance != std::nullopt) {
				std::cout << balance.value() << std::endl;
			}
			else {
				std::cout << "ERROR\n";
			}
		}
		else if (command == "TRANSFER") {

			std::string from, to;
			int count;

			s >> from >> to >> count;
			db.Transfer(from, to, count);
		}
		else if (command == "INCOME") {

			int p;
			s >> p;

			db.Income(p);

		}

	}

}