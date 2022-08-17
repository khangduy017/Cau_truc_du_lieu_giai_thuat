#include<iostream>
using namespace std;

class BST {
public:
	struct Node {
		int data;
		Node* left, * right;
	};
	void insert(int value) {
		insertNode(root, value);
	}
	void print2D() {
		print2DUtil(root, 0);
	}
	bool search(int value) {
		if (searchNode(root, value) == nullptr)return false;
		else return true;
	}
	void PreOrder() {
		PreOrderNode(root);
	}
	void InOrder() {
		InOrderNode(root);
	}
	void PostOrder() {
		PostOrderNode(root);
	}
	int max() {
		Node*temp= maximumNode(root);
		return temp->data;
	}
	int min() {
		Node* temp = minimumNode(root);
		return temp->data;
	}
	void Delete(int x) {
		deleteNode(root, x);
	}
	void clearTree() {
		deleteTree(root);
		root = nullptr;
	}
public:
	Node* root;
	BST() {
		root = nullptr;
	}

	void insertNode(Node*& root, int value) {
		if (root == nullptr) {
			Node* node = new Node;
			node->data = value;
			node->left = nullptr;
			node->right = nullptr;
			root = node;
		}
		else {
			if (value < root->data) insertNode(root->left, value);
			else  insertNode(root->right, value);
		}
	}

	void print2DUtil(Node* root, int space) {
		if (root == nullptr) return;
		space += 10;
		print2DUtil(root->right, space);
		cout << endl;
		for (int i = 10; i < space; i++) cout << " ";
		cout << root->data << "\n";
		print2DUtil(root->left, space);
	}
	
	Node* searchNode(Node* root, int value) {
		if (root == nullptr || root->data == value) return root;
		if (root->data > value)searchNode(root->left, value);
		else searchNode(root->right, value);
	}
	void PreOrderNode(Node* root) {
		if (root != nullptr) {
			cout << root->data << " ";
			PreOrderNode(root->left);
			PreOrderNode(root->right);
		}
	}
	void InOrderNode(Node* root) {
		if (root != nullptr){
			InOrderNode(root->left);
			cout << root->data << " ";
			InOrderNode(root->right);
		}
	}
	void PostOrderNode(Node* root) {
		if (root != nullptr) {
			PostOrderNode(root->left);
			PostOrderNode(root->right);
			cout << root->data << " ";
		}
	}
	Node* minimumNode(Node* root) {
		if (root->left == nullptr) return root;
		return minimumNode(root->left);
	}
	Node* maximumNode(Node* root) {
		if (root->right == nullptr) return root;
		return maximumNode(root->right);
	}

	Node* deleteNode(Node* root, int key) {
		if (root == nullptr) return root;
		if (key < root->data)
			root->left = deleteNode(root->left, key);
		else if (key > root->data)
			root->right = deleteNode(root->right, key);
		else {
			if (root->left == nullptr) {
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr) {
				Node* temp = root->left;
				delete root;
				return temp;
			}
			Node* temp = minimumNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
		return root;
	}

	void deleteTree(Node* node) {
		if (node == nullptr) return;
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
};

int main() {
	BST tree;
	int a[]{ 14,10,15,13,12,6,17,11,16,18};
	for (auto e : a) tree.insert(e);
	tree.print2D();
	cout << endl;
	/*
	if (tree.search(x)) cout << "YES";
	else cout << "NO";*/
	/*tree.PreOrder();
	cout << endl;
	tree.InOrder();
	cout << endl;
	tree.PostOrder();
	cout << endl;
	cout <<"Max : "<<tree.max() << endl;
	cout <<"Min : " << tree.min();*/

	int x;
	while (true) {
		cout << "PreOrder : ";
		tree.PreOrder();
		cout << "\nENTER X : ";
		cin >> x;
		tree.Delete(x);
		cout << "After delete : \n";
		cout << "PreOrder : ";
		tree.PreOrder();
		cout << endl;
		tree.print2D();
	}
	/*cout << "\n=======================================================================\n";
	tree.clearTree();
	tree.PreOrder();
	cout <<"Binary Tree is clear !!!";
	tree.print2D();*/
}