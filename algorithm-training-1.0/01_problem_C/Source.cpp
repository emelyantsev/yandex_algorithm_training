#include <string>
#include <iostream>


std::string process_number(const std::string& str) {

	std::string res;

	for (char c : str) {
		if (isdigit(c)) {
			res.push_back(c);
		}
	}

	if (res.size() == 7) {
		return "8495" + res;
	}
	else if (res.size() == 11) {
		res[0] = '8';
		return res;
	}
	else {
		return res;
	}
}

void compare_and_print(const std::string& ls, const std::string& rs) {

	std::cout << ( ls == process_number(rs) ? "YES" : "NO" ) << std::endl;
}

int main() {

	std::string s1, s2, s3, s4;

	std::cin >> s1 >> s2 >> s3 >> s4;

	s1 = process_number(s1);

	compare_and_print(s1, s2);
	compare_and_print(s1, s3);
	compare_and_print(s1, s4);

	return 0;
}