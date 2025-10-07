#include <iostream>
#include <vector>

#define SQUARE(x) (x)*(x)

struct Point {
	long long  x;
	long long y;
};




bool has_equal_edges(const Point& p1, const Point& p2, const Point& p3) {

	long long l12 = SQUARE(p1.x - p2.x) + SQUARE(p1.y - p2.y);
	long long l13 = SQUARE(p1.x - p3.x) + SQUARE(p1.y - p3.y);
	long long l23 = SQUARE(p2.x - p3.x) + SQUARE(p2.y - p3.y);

	return l12 == l13 || l12 == l23 || l13 == l23;
}


bool has_positive_area(const Point& p1, const Point& p2, const Point& p3) {

	return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y) != 0;
}


int main() {


	int n;
	std::cin >> n;

	std::vector<Point> p(n);

	for (int i = 0; i < n; ++i) {

		std::cin >> p[i].x >> p[i].y;
	}

	int l = 0;
	int m = 1;
	int r = 2;

	long long answer = 0;

	while (true) {


		if (has_equal_edges(p[l], p[m], p[r]) && has_positive_area(p[l], p[m], p[r])) {
			++answer;
		}

		if (l == n - 3 && m == n - 2 && r == n - 1) {
			break;
		}
		
		if (r != n - 1) {
			++r;
		}
		else if (m != n - 2) {
			++m;
			r = m + 1;
		}
		else {
			++l;
			m = l + 1;
			r = l + 2;
		}

	}

	std::cout << answer << std::endl;

}
