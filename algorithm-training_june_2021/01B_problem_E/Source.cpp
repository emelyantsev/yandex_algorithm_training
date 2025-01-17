#include <iostream>
#include <array>
#include <algorithm>

struct Point {
	int x;
	int y;
};


bool isInside(const Point& p, int d) {

	if (p.x < 0 || p.y < 0) {
		return false;
	}

	if (p.x > d || p.y > d) {
		return false;
	}

	int dx = d - p.x;

	if (p.y > dx) {
		return false;
	}


	return true;
}


int main() {

	int d;
	std::cin >> d;

	Point p;
	std::cin >> p.x >> p.y;

	if (isInside(p, d)) {
		std::cout << 0 << std::endl;
	}
	else {

		std::array<Point, 3> points{ Point{0,0}, Point{d, 0}, Point{0,d } };

		auto it = std::min_element(points.begin(), points.end(), [p](const Point& p1, const Point& p2) {
			
			int d1 = (p1.x - p.x) * (p1.x - p.x) + (p1.y - p.y) * (p1.y - p.y);
			int d2 = (p2.x - p.x) * (p2.x - p.x) + (p2.y - p.y) * (p2.y - p.y);

			return d1 < d2;

			});

		int res = it - points.begin() + 1;
		std::cout << res << std::endl;
	}

	return 0;
}