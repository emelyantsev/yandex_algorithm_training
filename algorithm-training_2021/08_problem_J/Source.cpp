#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <cassert>
#include <queue>

class HTree {

public:

	HTree() {}

	void AddPair(const std::string& child, const std::string& parent) {

		children_of[parent].push_back(child);
		children.insert(child);

		parent_of[child] = parent;
	}

	void SetupRoot() {

		for (const auto& [parent, _] : children_of) {

			if (children.count(parent) == 0) {
				root = parent;
				break;
			}
		}
	}

	std::map<std::string, int> GetHeightsMap() {

		std::map<std::string, int> result;

		std::queue<std::string> q;
		
		result[root] = 0;

		for (const std::string& child : children_of[root]) {
			q.push(child);
		}

		while (!q.empty()) {

			std::string top = q.front();
			q.pop();

			for (const std::string& child : children_of[top]) {
				q.push(child);
			}

			assert( result.count( parent_of[top] ) == 1);

			result[top] = result[parent_of[top]] + 1;
		}



		return result;
	}


private:



	std::unordered_map<std::string, std::vector<std::string> > children_of;
	std::unordered_map<std::string, std::string > parent_of;
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

	auto ancestorsMap = htree.GetHeightsMap();

	for (const auto& [name, count] : ancestorsMap) {

		std::cout << name << " " << count << std::endl;
	}

	return 0;
}