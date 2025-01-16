#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <climits>
#include <cmath>

#define SQUARE(x) (x)*(x)

struct Point {
	long long x;
	long long y;
};

bool has_positive_area(Point p1, Point p2, Point p3) {

	p2.x -= p1.x;
	p2.y -= p1.y;

	p3.x -= p1.x;
	p3.y -= p1.y;



	return p2.x + p3.x != 0 || p2.y + p3.y != 0;
}

long long distance(const Point& p1, const Point& p2) {

	long long result = SQUARE(p1.x - p2.x) + SQUARE(p1.y - p2.y);

	assert(result > 0 && result < LLONG_MAX);

	return result;
}


int main() {


	int n;
	std::cin >> n;

	std::vector<Point> p(n);

	for (int i = 0; i < n; ++i) {

		std::cin >> p[i].x >> p[i].y;
		assert(std::abs(p[i].x) <= 1000000000 && std::abs(p[i].y) <= 1000000000);
	}

	long long ans = 0;

	for (int i = 0; i < n; ++i) {

		std::unordered_map<long long, std::vector<int> > edges;

		for (int j = 0; j < n; ++j) {

			if (i == j) {
				continue;
			}

			long long d = distance( p[i], p[j] ) ;

			edges[d].push_back(j);
		}

		for (const auto& [_, ids] : edges) {

			for (int ii = 0; ii < ids.size(); ++ii) {

				for (int jj = ii + 1; jj < ids.size(); ++jj) {


					if (has_positive_area(p[i], p[ids[ii]], p[ids[jj]])) {
						++ans;
					}
				}
			}

		}


	}


	std::cout << ans << std::endl;

}


