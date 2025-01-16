#include <iostream>
#include <vector>
#include <cassert>


bool is_valid(long long m, long long k, long long p, long long n, long long c) {

	long long k_ = (p - 1) * m * c + (n - 1) * c;

	long long diff = k - k_;

	if (diff >= 1 && diff <= c) {
		return true;
	}
	else {
		return false;
	}
}


void get_answer(long long k, long long m, long long c, long long& p, long long& n) {


	long long n_ = (k - 1) / c;
	long p_ = n_ / m;


	p = p_ + 1;
	n = n_ - p_ * m + 1;

}


int main() {

	long long k1, m, k2, p2, n2;

	std::cin >> k1 >> m >> k2 >> p2 >> n2;

	assert(k1 > 0 && m > 0 && k2 > 0 && p2 > 0 && n2 > 0);

	if (n2 > m) {

		std::cout << "-1 -1" << std::endl;
		return 0;
	}

	bool has_answer = false;
	long long pa = -1;
	long long na = -1;


	for (long long c = 1; c <= 1000000; ++c) {

		if (!is_valid(m, k2, p2, n2, c)) {

			continue;
		}
		else {
			bool stop = true;
		}

		long long pc, nc;

		get_answer(k1, m, c, pc, nc);

		if (!has_answer) {

			pa = pc;
			na = nc;
			has_answer = true;
		}
		else {

			if (pa != pc) {
				pa = 0;
			}

			if (na != nc) {
				na = 0;
			}

			if (pa == 0 && na == 0) {
				break;
			}

		}

	}

	std::cout << pa << " " << na << std::endl;


	return 0;
}