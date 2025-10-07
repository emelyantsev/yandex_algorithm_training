#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <queue>

struct Point3D {

	int z;
	int y;
	int x;

	inline bool operator==( const Point3D& other ) const
	{
		return y == other.y && x == other.x && z == other.z;
	}
};

template <>
struct std::hash<Point3D> {

	std::size_t operator()( const Point3D& point ) const noexcept
	{
		std::size_t h1 = std::hash<int>{}( point.x );
		std::size_t h2 = std::hash<int>{}( point.y );
		std::size_t h3 = std::hash<int>{}( point.z );

		return ( h1 ^ ( h2 << 1 ) ) ^ h3;
	}
};

class Solution {

public:

	void ReadInput() {
	
		std::cin >> n;

		cave.reserve( n );

		for( int i = 0; i < n; ++i ) {

			ReadLevel();
		}

	}

	int Solve()
	{
	
		std::queue<Point3D> q;
		std::unordered_map<Point3D, int> points_distances;

		std::unordered_set<Point3D> visited;

		q.push( start );
		points_distances[start] = 0;
		visited.insert( start );

		while( !q.empty() ) {

			Point3D point = q.front();
			q.pop();

			if( point.z == 0 ) {

				return points_distances[point];
			}

			auto next_points = getNextPoints( point );

			for( const auto& next_point : next_points ) {

				if( visited.count( next_point ) == 0 ) {

					visited.insert( next_point );
					points_distances[next_point] = points_distances[point] + 1;
					q.push( next_point );
				}
			}


		}
		
		
		return -1;
	}

private:

	void ReadLevel()
	{
		Level level;
		level.reserve( n );

		std::string row;

		for( int i = 0; i < n; ++i ) {

			std::cin >> row;

			for( int j = 0; j < n; ++j ) {

				if( row[j] == 'S' ) {

					start = { static_cast<int>( cave.size() ), i, j };
				}
			}

			level.push_back( row );
		}

		cave.push_back( level );
	}

	std::vector<Point3D> getNextPoints( const Point3D& point )
	{
		std::vector<Point3D> result;

		std::vector<Point3D> steps = {

			{1,0,0},
			{-1,0,0},
			{0,1,0},
			{0,-1,0},
			{0,0,1},
			{0,0,-1}
		};

		for( const auto& step : steps ) {

			Point3D next_point = { point.z + step.z, point.y + step.y, point.x + step.x };

			if( isValid( next_point ) ) {

				result.push_back( next_point );
			}
		}

		return result;

	}

	bool isValid( const Point3D& point )
	{
		if( point.z >= 0 && point.z < n && point.y >= 0 && point.y < n && point.x >= 0 && point.x < n && cave[point.z][point.y][point.x] != '#' ) {
			return true;
		}
		return false;
	}


	using Level = std::vector<std::string>;

	std::vector<Level> cave;

	Point3D start;
	int n;
};


int main()
{
	Solution sln;

	sln.ReadInput();

	auto res = sln.Solve(); 

	std::cout << res << std::endl;

	return 0;
}