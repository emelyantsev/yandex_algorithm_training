#include <iostream>
#include <unordered_set>
#include <cstdlib>
#include <vector>
#include <utility> 

struct Point {

    int y;
    int x;

    inline bool operator==(const Point& p) const {
        return y == p.y && x == p.x;
    }

};

namespace std {
    template <> struct hash<Point> {

        inline size_t operator()(const Point& p) const {
        
            std::hash<int> int_hasher;
            return int_hasher(p.y) ^ int_hasher(p.x);
        }
    };
}


int distance(const Point& p1, const Point& p2) {

    return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
}


std::vector<Point> generate(const Point& p, int t) {

    std::vector<Point> result;

    for (int i = -t; i <= t; ++i) {

        int maxj = t - std::abs(i);

        for (int j = -maxj; j <= maxj; ++j) {

            Point next = p;
            next.x += i;
            next.y += j;

            result.push_back(next);
        }

    }

    return result;
}

int main() {

    int t, d, n;
    std::cin >> t >> d >> n;

    std::unordered_set<Point> points;
    points.insert( Point{ 0, 0 } );

    for (int i = 0; i < n; ++i) {

        std::unordered_set<Point> next_points;

        Point p;
        std::cin >> p.x >> p.y;

        for (const Point& prev : points) {

            for (const Point& next : generate(prev, t)) {

                if (distance(next, p) <= d) {
                    next_points.insert(next);
                }
            }
        }

        points = std::move(next_points);
    }

    std::cout << points.size() << std::endl;

    for (const Point& p : points) {
        std::cout << p.x << " " << p.y << std::endl;
    }

}