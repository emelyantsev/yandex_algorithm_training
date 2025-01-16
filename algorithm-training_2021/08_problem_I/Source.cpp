#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <cassert>

class HTree {

public:

	HTree() {}

	void AddPair(const std::string& child, const std::string& parent) {

		children_of[parent].push_back(child);
		children.insert(child);
	}

	void SetupRoot() {

		for (const auto& [parent, _] : children_of) {

			if (children.count(parent) == 0) {
				root = parent;
				break;
			}
		}
	}

	std::map<std::string, int> GetAncestorsCountMap() {

		std::map<std::string, int> result;

		std::stack<std::string> s1;
		s1.push(root);

		std::stack < std::string > s2;

		while ( !s1.empty() ) {

			std::string top = s1.top();
			s1.pop();

			for (const std::string& child : children_of[top] ) {
				s1.push(child);
			}

			s2.push(top);
		}


		while ( !s2.empty() )
		{
			std::string top = s2.top();
			s2.pop();
			
			if (children_of.count(top) == 0) {

				result[top] = 0;
			}
			else {

				int count = 0;

				for (const std::string& child : children_of[top]) {

					assert(result.count(child) == 1);
					count += 1 + result[child];
				}
				result[top] = count;
			}

		}


		return result;
	}


private:



	std::unordered_map<std::string, std::vector<std::string> > children_of;
	std::unordered_set<std::string> children;
	std::string root;

};




int main() {

	int N;
	std::cin >> N;

	HTree htree;

	for (int i = 0; i < N - 1; ++i) {

		std::string child, parent;
		std::cin >> child >> parent;

		htree.AddPair(child, parent);
	}

	htree.SetupRoot();

	auto ancestorsMap = htree.GetAncestorsCountMap();

	for (const auto& [name, count] : ancestorsMap) {

		std::cout << name << " " << count << std::endl;
	}

	return 0;
}