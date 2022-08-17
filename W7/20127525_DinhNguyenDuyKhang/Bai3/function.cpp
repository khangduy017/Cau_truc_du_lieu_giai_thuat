#include"function.h"

int height(Node* root) {
	if (root == nullptr) return 0;
	return root->height;
}
int getBalance(Node* root) {
	if (root == nullptr) return 0;
	return height(root->left) - height(root->right);
}

Node* rightRotate(Node* root) {
	Node* x = root->left;
	Node* t = x->right;
	x->right = root;
	root->left = t;

	root->height = max(height(root->left), height(root->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

Node* leftRotate(Node* root) {
	Node* x = root->right;
	Node* t = x->left;
	x->left = root;
	root->right = t;

	root->height = max(height(root->left), height(root->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

Node* insertNode(Node*& root, int value) {
	if (root == nullptr) {
		Node* p = new Node;
		p->data = value;
		p->left = nullptr;
		p->right = nullptr;
		p->height = 1;
		root = p;
	}

	if (value > root->data) {
		root->right = insertNode(root->right, value);
	}
	else if (value < root->data) {
		root->left = insertNode(root->left, value);
	}
	else return root;

	root->height = max(height(root->left), height(root->right)) + 1;

	int balance = getBalance(root);

	if (balance > 1 && value < root->left->data) {
		return rightRotate(root);
	}
	if (balance < -1 && value > root->right->data) {
		return leftRotate(root);
	}
	if (balance > 1 && value > root->left->data) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance < -1 && value < root->right->data) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
void insert(Node*& root,int data) {
	root = insertNode(root,data);
}

int heightMin(Node* root) {
	if (root->left == nullptr && root->right == nullptr) return 1;
	else if (root->right == nullptr && root->left != nullptr) 
		return 1+heightMin(root->left);
	else if (root->left == nullptr && root->right != nullptr) 
		return 1+heightMin(root->right);
	return min(heightMin(root->left), heightMin(root->right)) + 1;
}

string checkAVL(Node* root) {
	if (height(root) == heightMin(root)) return "Yes";
	return "No";
}
