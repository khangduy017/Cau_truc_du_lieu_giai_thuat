#include"function.h"

void insertNode(Node*& root, string value) {
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

void PreOrderNode(Node* root) {
	if (root != nullptr) {
		cout << root->data << " ";
		PreOrderNode(root->left);
		PreOrderNode(root->right);
	}
}
void InOrderNode(Node* root) {
	if (root != nullptr) {
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