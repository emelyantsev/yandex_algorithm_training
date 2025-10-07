#include <iostream>
#include <map>
#include <string>

long long GetSum(long long n) {

	return n * (n + 1) / 2;
}


int main() {


	std::string s;
	std::cin >> s;

	long long n = s.size();

	long long sum = GetSum(n);

	std::map<char, long long> char_counts;

	for (char c : s) {

		char_counts[c] += sum;
	}


	for (int i = 0; i < s.size() - 1; ++i) {

		long long len = s.size() - 1;
		long long li = len - i;
		char_counts[s[i]] -= GetSum(li);
	}

	for (int i = 0; i < s.size() - 1; ++i) {

		long long len = s.size() - 1;
		long long li = len - i;
		char_counts[s[s.size()-1-i]] -= GetSum(li);
	}

	for (const auto& [c, count] : char_counts) {
		std::cout << c << ": " << count << std::endl;
	}

	return 0;
}

