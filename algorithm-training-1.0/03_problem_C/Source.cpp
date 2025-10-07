#include <set>
#include <iostream>


template<typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& set)
{
	out << set.size() << std::endl;

	for (const T& item : set) {
		out << item << " ";
	}

	out << std::endl;

	return out;
}


int main() {

	int N, M;

	std::cin >> N >> M;

	std::set<int> s1, s2;

	for (int i = 0; i < N; ++i) {

		int num;
		std::cin >> num;
		s1.insert(num);
	}


	for (int i = 0; i < M; ++i) {

		int num;
		std::cin >> num;
		s2.insert(num);
	}

	std::set<int> common, u1, u2;


	for (int val : s1) {


		if (s2.count(val) == 1) {
			common.insert(val);
		}
		else {
			u1.insert(val);
		}
	}

	for (int val : s2) {


		if (s1.count(val) == 0) {
			u2.insert(val);
		}
	}

	std::cout << common << u1 << u2;

}