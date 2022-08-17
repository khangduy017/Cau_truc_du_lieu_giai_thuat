#include"function.h"

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

void PreOrderNode(Node* root) {
	if (root != nullptr) {
		cout << root->data << " ";
		PreOrderNode(root->left);
		PreOrderNode(root->right);
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

void Delete(Node*& root,int x) {
	Node*p=deleteNode(root, x);
	if (p == nullptr) cout<<-1;
	root = deleteNode(root, x);
}

bool search(Node* root, int k){
	if (root == nullptr) return false;
	if (root->data == k) return true;

	if (root->data > k) return search(root->left, k);
	else if (root->data < k) return search(root->right, k);
}

bool SumOfNode(Node* root2, int value){
	if (root2 == nullptr) return false;
	SumOfNode(root2->left, value);
	SumOfNode(root2->right, value);
	return search(root2, value - root2->data);
}
