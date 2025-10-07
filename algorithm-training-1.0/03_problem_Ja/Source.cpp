#include <iostream>
#include <algorithm>
#include <vector>

struct DiagRect {

	int min_diff;
	int max_diff;
	int min_sum;
	int max_sum;
};

struct Point {
	int x;
	int y;
};


DiagRect inflate(const DiagRect& r, int t) {
	
	DiagRect result = r;
	result.min_diff -= t;
	result.max_diff += t;
	result.min_sum -= t;
	result.max_sum += t;

	return result;
}

DiagRect intersect(const DiagRect& r1, const DiagRect& r2) {

	return { std::max(r1.min_diff, r2.min_diff), std::min(r1.max_diff, r2.max_diff), std::max(r1.min_sum, r2.min_sum), std::min(r1.max_sum, r2.max_sum) } ;
}


int main() {

	int t, d, n;
	std::cin >> t >> d >> n;

	DiagRect zone{ 0,0,0,0 };

	for (int i = 0; i < n; ++i) {

		int x, y;
		std::cin >> x >> y;

		zone = intersect( inflate(zone, t), { y - x - d, y - x + d, y + x - d, y + x + d } );
	}

	std::vector<Point> points;

	for (int diff = zone.min_diff; diff <= zone.max_diff; ++diff) {

		for (int sum = zone.min_sum; sum <= zone.max_sum; ++sum) {

			int y2 = diff + sum;

			if (y2 % 2 == 0) {

				int y = y2 / 2;
				int x = y - diff;

				points.push_back(Point{ x,y });
			}

		}
	}

	std::cout << points.size() << std::endl;
	for (const Point& p : points) {

		std::cout << p.x << " " << p.y << std::endl;
	}

}