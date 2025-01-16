#include <iostream>
#include <memory>
#include <algorithm>
#include <initializer_list>
#include <cassert>
#include <unordered_map>
#include <cmath>

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


	class ConstReverseIterator {

	public:

		ConstReverseIterator(const Node*);

		ConstReverseIterator& operator++();

		const T& operator*() const;

		friend bool operator==(const ConstReverseIterator& left, const ConstReverseIterator& right) { return left.node == right.node; }
		friend bool operator!=(const ConstReverseIterator& left, const ConstReverseIterator& right) { return left.node != right.node; }

	private:

		const Node* node;
	};

	class ConstIterator {

	public:

		ConstIterator(const Node*);

		ConstIterator& operator++();

		const T& operator*() const;

		friend bool operator==(const ConstIterator& left, const ConstIterator& right) { return left.node == right.node; }
		friend bool operator!=(const ConstIterator& left, const ConstIterator& right) { return left.node != right.node; }

		bool IsLeaf() const { return node == nullptr ? false : node->left.get() == nullptr && node->right.get() == nullptr; }
		bool IsFork() const { return node == nullptr ? false : node->left.get() != nullptr && node->right.get() != nullptr; }
		bool IsBranch() const { return node == nullptr ? false : (node->left.get() == nullptr) != (node->right.get() == nullptr); }
		const Node* GetNode() { return node;  };

	private:

		const Node* node;
	};


public:

	BST() : root(nullptr) {}
	BST(std::initializer_list<T> l);

	int GetHeight() const;
	bool Contains(const T& key) const;
	std::pair<Node*, bool> Insert(const T& key);
	int InsertAndGetDepth(const T& key);

	ConstIterator begin() const;
	ConstIterator end() const;

	ConstReverseIterator rbegin() const;
	ConstReverseIterator rend() const;

	bool IsBalanced() const;

private:

	int height(const Node*) const;
	bool isBalanced(const Node*) const;

private:

	std::unique_ptr<Node> root;
	mutable std::unordered_map<const Node*, int> heightsMap;

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

		if (heightsMap.count(node)) {
			return heightsMap[node];
		}
		else {
			int h = 1 + std::max(height(node->left.get()), height(node->right.get()));
			heightsMap[node] = h;
			return h;
		}
	}
};

template<typename T>
bool BST<T>::isBalanced(const Node* node) const {

	if (node == nullptr) {
		return true;
	}
	else {

		int height_diff = height(node->left.get()) - height(node->right.get());
		return std::abs(height_diff) <= 1;
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


template<typename T>
bool BST<T>::IsBalanced() const {

	for (auto it = this->begin(); it != this->end(); ++it) {
		if (!isBalanced(it.GetNode())) {
			return false;
		}
	}

	return true;
}


template<typename T>
BST<T>::ConstIterator::ConstIterator(const BST<T>::Node* node_) : node(node_) {}

template<typename T>
typename BST<T>::ConstIterator& BST<T>::ConstIterator::operator++() {

	if (node == nullptr) {
		assert(false);
		return *this;
	}

	if (node->right.get() != nullptr) {

		const BST<T>::Node* next_node = node->right.get();

		while (next_node->left.get() != nullptr) {
			next_node = next_node->left.get();
		}

		node = next_node;
		return *this;
	}
	else {

		const BST<T>::Node* current_node = node;

		while (true) {

			if (current_node->parent == nullptr || current_node->parent->left.get() == current_node) {
				node = current_node->parent;
				return *this;
			}
			else {
				current_node = current_node->parent;
			}
		}

	}

}

template<typename T>
const T& BST<T>::ConstIterator::operator*() const {

	if (node == nullptr) {
		assert(false);
	}

	return node->val;

}


template<typename T>
BST<T>::ConstReverseIterator::ConstReverseIterator(const BST<T>::Node* node_) : node(node_) {}

template<typename T>
typename BST<T>::ConstReverseIterator& BST<T>::ConstReverseIterator::operator++() {

	if (node == nullptr) {
		assert(false);
		return *this;
	}

	if (node->left.get() != nullptr) {

		const BST<T>::Node* prev_node = node->left.get();

		while (prev_node->right.get() != nullptr) {
			prev_node = prev_node->right.get();
		}

		node = prev_node;
		return *this;
	}
	else {

		const BST<T>::Node* current_node = node;

		while (true) {

			if (current_node->parent == nullptr || current_node->parent->right.get() == current_node) {
				node = current_node->parent;
				return *this;
			}
			else {
				current_node = current_node->parent;
			}
		}

	}

}

template<typename T>
const T& BST<T>::ConstReverseIterator::operator*() const {

	if (node == nullptr) {
		assert(false);
	}

	return node->val;

}





template<typename T>
typename BST<T>::ConstIterator BST<T>::begin() const {

	if (root.get() == nullptr) {

		return BST<T>::ConstIterator(nullptr);
	}

	BST<T>::Node* current = root.get();

	while (current->left.get() != nullptr) {
		current = current->left.get();
	}

	return BST<T>::ConstIterator(current);
}


template<typename T>
typename BST<T>::ConstIterator BST<T>::end() const {

	return BST<T>::ConstIterator(nullptr);
}

template<typename T>
typename BST<T>::ConstReverseIterator BST<T>::rbegin() const {

	if (root.get() == nullptr) {

		return BST<T>::ConstReverseIterator(nullptr);
	}

	BST<T>::Node* current = root.get();

	while (current->right.get() != nullptr) {
		current = current->right.get();
	}

	return BST<T>::ConstReverseIterator(current);
}


template<typename T>
typename BST<T>::ConstReverseIterator BST<T>::rend() const {

	return BST<T>::ConstReverseIterator(nullptr);
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

		for (const int& elem : bst) {

			std::cout << elem << " ";
		}

		std::cout << std::endl;


		for (auto it = bst.rbegin(); it != bst.rend(); ++it) {
			std::cout << *it << " ";
		}

		std::cout << std::endl;



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

			bst.Insert(num);
		}
	}

	std::cout << ( bst.IsBalanced() ? "YES" : "NO" ) << std::endl;

	return 0;
}