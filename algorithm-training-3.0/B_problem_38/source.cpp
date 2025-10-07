#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <queue>

struct Point {

	int y;
	int x;

	inline bool operator==( const Point& other ) const
	{
		return y == other.y && x == other.x;
	}
};

struct PointHash {

	std::size_t operator()( const Point& point ) const noexcept
	{
		std::size_t h1 = std::hash<int>{}( point.x  );
		std::size_t h2 = std::hash<int>{}( point.y );

		return h1 ^ ( h2 << 1 ); 
	}
};

template <>
struct std::hash<Point> {

	std::size_t operator()( const Point& point ) const noexcept
	{
		std::size_t h1 = std::hash<int>{}( point.x );
		std::size_t h2 = std::hash<int>{}( point.y );

		return h1 ^ ( h2 << 1 );
	}
};


class Solution {

public:

	void ReadInput()
	{
		std::cin >> n >> m;

		std::cin >> p.y >> p.x;

		int q;
		std::cin >> q;

		for( int i = 0; i < q; ++i ) {

			Point flea;
			std::cin >> flea.y >> flea.x;

			fleas.insert( flea );
		}

	}

	int Solve()
	{
		std::unordered_set<Point> visited;
		std::unordered_map<Point, int> points_distances;


		points_distances[p] = 0;
		visited.insert( p );

		std::queue<Point> q;
		q.push( p );


		int result = 0;


		while( !q.empty() && !fleas.empty() ) {

			Point point = q.front();
			q.pop();

			if( fleas.count( point ) ) {
				fleas.erase( point );
				result += points_distances[point];
			}

			auto next_points = getNextPoints( point );

			for( const Point& next_point : next_points ) {

				if( visited.count( next_point ) == 0 ) {

					visited.insert( next_point );
					q.push( next_point );
					points_distances[next_point] = points_distances[point] + 1;
				}
			}

		}

		if( !fleas.empty() ) {
			return -1;
		}
		else {

			return result;
		}

	}

	std::vector<Point> getNextPoints( const Point& point )
	{
		std::vector<Point> result;


		Point p1 = { point.y - 2, point.x - 1 };

		if( isValid( p1 ) ) {
			result.push_back( p1 );
		}

		Point p2 = { point.y - 2, point.x + 1 };

		if( isValid( p2 ) ) {
			result.push_back( p2 );
		}

		Point p3 = { point.y - 1, point.x + 2 };

		if( isValid( p3 ) ) {
			result.push_back( p3 );
		}

		Point p4 = { point.y + 1, point.x + 2 };

		if( isValid( p4 ) ) {
			result.push_back( p4 );
		}

		Point p5 = { point.y + 2, point.x - 1 };

		if( isValid( p5 ) ) {
			result.push_back( p5 );
		}

		Point p6 = { point.y + 2, point.x + 1 };

		if( isValid( p6 ) ) {
			result.push_back( p6 );
		}

		Point p7 = { point.y - 1, point.x - 2 };

		if( isValid( p7 ) ) {
			result.push_back( p7 );
		}

		Point p8 = { point.y + 1, point.x - 2 };

		if( isValid( p8 ) ) {
			result.push_back( p8 );
		}

		return result;
	}

	bool isValid( const Point& point )
	{
		return point.y >= 1 && point.y <= n && point.x >= 1 && point.x <= m;
	}


private:

	int n;
	int m;

	Point p;

	std::unordered_set<Point> fleas;
	
};



int main()
{

	Solution sln;

	sln.ReadInput();

	auto res = sln.Solve();

	std::cout << res << std::endl;

	return 0;
}