#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cassert>

struct Time {

	int h;
	int m;
	int s;

	Time() : h(0), m(0), s(0) {}

	Time(int hh, int mm, int ss) : h(hh), m(mm), s(ss) {}

	Time(int ts) {

		h = ts / 3600;
		m = ts % 3600 / 60;
		s = ts % 60;

		if (h >= 24) {
			h = h % 24;
		}

	}

	int TotalSeconds() {
		return h * 60 * 60 + m * 60 + s;
	}
};


std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << std::setfill('0') << std::setw(2) <<  t.h << ':' << std::setfill('0') << std::setw(2) << t.m << ':' << std::setfill('0') << std::setw(2) << t.s;
	return os;
}

std::istream& operator>> (std::istream& is, Time& t)
{
	is >> t.h;
	char c;
	is >> c;
	assert(c == ':');
	is >> t.m;
	is >> c;
	assert(c == ':');
	is >> t.s;
	return is;
}


int main() {

	Time a, b, c;

	std::cin >> a >> b >> c;

	int ta = a.TotalSeconds();
	int tc = c.TotalSeconds();

	if (tc < ta) {
		tc += 24 * 60 * 60;
	}

	int diff = (tc - ta) / 2 + (tc - ta) % 2;

	int tb = b.TotalSeconds();

	int ans = tb + diff;

	Time res(ans);

	std::cout << res << std::endl;


	return EXIT_SUCCESS;
}