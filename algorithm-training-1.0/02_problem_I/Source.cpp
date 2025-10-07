#include <iostream>
#include <vector>
#include <unordered_set>

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

int calcCounts(const Point& p, const std::unordered_set<Point>& mines, int N, int M) {

    int res = 0;

    for (const Point& step : std::vector<Point>{ {0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}  }) {

        Point next = { p.y + step.y, p.x + step.x };

        if (next.y >= 0 && next.y < N && next.x >= 0 && next.y < M && mines.count(next) == 1 ) {
            ++res;
        }
    }

    return res;
}

int main() {


    int N, M, K;
    std::cin >> N >> M >> K;


    std::unordered_set<Point> mines;

    for (int i = 0; i < K; ++i) {

        Point p;
        std::cin >> p.y >> p.x;
        --p.y;
        --p.x;
        mines.insert(p);
    }


    std::vector<std::vector<char> > result(N, std::vector<char>(M, '0'));

    for (int i = 0; i < N; ++i) {


        for (int j = 0; j < M; ++j) {


            Point p;
            p.y = i;
            p.x = j;

            if (mines.count(p) == 1) {
                result[i][j] = '*';
            }
            else {
                int count = calcCounts(p, mines, N, M);
                result[i][j] = '0' + count;
            }

        }

    }

    for (int i = 0; i < N; ++i) {

        for (int j = 0; j < M; ++j) {

            std::cout << result[i][j] << " ";

        }

        std::cout << std::endl;
    }


}