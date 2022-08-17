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

int maxx(int a, int b) {
	return (a > b) ? a : b;
}

int height(Node* root) {
	if (root == nullptr) return 0;
	return maxx(height(root->left), height(root->right)) + 1;
}

string checkAVL(Node* root) {
	int lh, rh;
	if (root == nullptr) return "Yes";
	lh = height(root->left);
	rh = height(root->right);
	if (abs(lh - rh) <= 1 && checkAVL(root->left) == "Yes" && checkAVL(root->right) == "Yes") return "Yes";
	return "No";
}
