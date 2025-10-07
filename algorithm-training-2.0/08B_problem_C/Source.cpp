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

			assert(result.count(parent_of[top]) == 1);

			result[top] = result[parent_of[top]] + 1;
		}



		return result;
	}


	bool IsAncestorOf(const std::string& name1, const std::string& name2) {


		std::string parentName = parent_of[name1];

		while (parentName != "") {

			if (parentName == name2) {
				return true;
			}
			else {
				parentName = parent_of[parentName];
			}
		}

		return false;
	}

	std::string GetMinCommonAncestor(const std::string& name1, const std::string& name2) {


		std::vector<std::string> anc1;
		anc1.push_back(name1);

		std::string parentName = parent_of[name1];

		while (parentName != "") {

			anc1.push_back(parentName);
			parentName = parent_of[parentName];
		}


		std::vector<std::string> anc2;
		anc2.push_back(name2);

		parentName = parent_of[name2];

		while (parentName != "") {

			anc2.push_back(parentName);
			parentName = parent_of[parentName];
		}

		int i = 0;
		int j = 0;

		std::string res;

		while (i < anc1.size() && j < anc2.size()) {

			if (anc1[anc1.size() - 1 - i] == anc2[anc2.size() - 1 - j]) {

				res = anc1[anc1.size() - 1 - i];
			}
			else {
				break;
			}
			++i;
			++j;
		}

		return res;
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

	std::string name1, name2;

	while (std::cin >> name1) {

		std::cin >> name2;

		std::cout << htree.GetMinCommonAncestor(name1, name2) << std::endl;

	}

	std::cout << std::endl;

	return 0;
}