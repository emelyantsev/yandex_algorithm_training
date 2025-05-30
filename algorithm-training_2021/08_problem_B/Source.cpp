#include <iostream>
#include <memory>
#include <algorithm>
#include <initializer_list>
#include <cassert>

template<typename T>
class BST {

public:

	struct Node {

		T val = {};
		Node* parent = nullptr;
		std::unique_ptr<Node> left = nullptr;
		std::unique_ptr<Node> right = nullptr;

		~Node() {

#ifdef _DEBUG
			std::cout << "~Node( " << val << " )" << std::endl;
#endif // DEBUG


		}
	};

public:

	BST() : root(nullptr) {}
	BST(std::initializer_list<T> l);

	int GetHeight() const;
	bool Contains(const T& key) const;
	std::pair<Node*, bool> Insert(const T& key);
	int InsertAndGetDepth(const T& key);

private:

	int height(const Node*) const;

private:

	std::unique_ptr<Node> root;

};

template<typename T>
BST<T>::BST(std::initializer_list<T> l) {

	for (const T& key : l) {
		this->Insert(key);
	}
}

template<typename T>
int BST<T>::GetHeight() const {
	return height(root.get());
}

template<typename T>
int BST<T>::height(const Node* node) const {

	if (node == nullptr) {
		return 0;
	}
	else {
		return 1 + std::max(height(node->left.get()), height(node->right.get()));
	}
};

template<typename T>
bool BST<T>::Contains(const T& key) const {

	Node* current = root.get();

	while (true) {

		if (current->val == key) {
			return true;
		}
		else if (key < current->val) {

			if (current->left != nullptr) {
				current = current->left.get();
			}
			else {
				return false;
			}
		}
		else {

			if (current->right != nullptr) {
				current = current->right.get();
			}
			else {
				return false;
			}
		}
	}

	return false;
}

template<typename T>
std::pair< typename BST<T>::Node*, bool> BST<T>::Insert(const T& key) {

	if (root == nullptr) {

		root = std::unique_ptr<Node>(new Node);
		root.get()->val = key;
		return { root.get(), true };
	}

	Node* current = root.get();

	while (true) {

		if (current->val == key) {
			return { current, false };
		}
		else if (key < current->val) {

			if (current->left != nullptr) {
				current = current->left.get();
			}
			else {
				current->left = std::unique_ptr<Node>(new Node);
				current->left.get()->val = key;
				current->left.get()->parent = current;
				return { current->left.get(), true };
			}
		}
		else {

			if (current->right != nullptr) {
				current = current->right.get();
			}
			else {
				current->right = std::unique_ptr<Node>(new Node);
				current->right.get()->val = key;
				current->right.get()->parent = current;
				return { current->right.get(), true };
			}
		}
	}
}

template<typename T>
int BST<T>::InsertAndGetDepth(const T& key) {



	if (root == nullptr) {

		root = std::unique_ptr<Node>(new Node);
		root.get()->val = key;
		return 1;
	}

	Node* current = root.get();

	int curr_depth = 1;

	while (true) {

		if (current->val == key) {
			return 0;
		}
		else if (key < current->val) {

			if (current->left != nullptr) {
				current = current->left.get();
				++curr_depth;
			}
			else {
				current->left = std::unique_ptr<Node>(new Node);
				current->left.get()->val = key;
				current->left.get()->parent = current;
				return curr_depth + 1;
			}
		}
		else {

			if (current->right != nullptr) {
				current = current->right.get();
				++curr_depth;
			}
			else {
				current->right = std::unique_ptr<Node>(new Node);
				current->right.get()->val = key;
				current->right.get()->parent = current;
				return curr_depth + 1;
			}
		}
	}

}

int main() {

#ifdef _DEBUG
	{
		// Unit test for tree

		BST<int> bst{ 7, 3, 2, 1, 9, 5, 4, 6, 8 };

		assert(bst.GetHeight() == 4);

		assert(bst.Contains(7));
		assert(bst.Contains(3));
		assert(bst.Contains(2));
		assert(bst.Contains(1));
		assert(bst.Contains(9));
		assert(bst.Contains(5));
		assert(bst.Contains(4));
		assert(bst.Contains(6));
		assert(bst.Contains(8));

		assert(!bst.Contains(10));

		assert(bst.Insert(7).second == false);
		assert(bst.Insert(3).second == false);
		assert(bst.Insert(2).second == false);
		assert(bst.Insert(1).second == false);
		assert(bst.Insert(9).second == false);
		assert(bst.Insert(5).second == false);
		assert(bst.Insert(4).second == false);
		assert(bst.Insert(6).second == false);
		assert(bst.Insert(8).second == false);
		assert(bst.Insert(10).second == true);
		assert(bst.Contains(10));
		assert(bst.Insert(10).second == false);

		std::initializer_list<int> l{ 7, 3, 2, 1, 9, 5, 4, 6, 8, 10 };

		for (int elem : l) {
			assert(bst.Contains(elem));
		}

	}
#endif // DEBUG



	BST<int> bst;

	while (true) {

		int num;
		std::cin >> num;
		
		if (num == 0) {
			break;
		}
		else {

			int depth = bst.InsertAndGetDepth(num);

			if (depth != 0) {
				std::cout << depth << std::endl;
			}

		}

			
	}

	return 0;
}