#include<iostream>
using namespace std;

class AVL {
public:
	struct Node {
		Node* left;
		Node* right;
		int data;
		int height;
	};
	void insertNode(int value) {
		root = insertNode(root, value);
	}
	void deleteNode(int value) {
		root = deleteNode(root, value);
	}
	void preOder() {
		preOder(root);
	}
	void print2DUtil() {
		print2DUtil(root, 0);
	}
	Node* root;
	AVL() {
		root = nullptr;
	}
	int max(int a, int b) {
		return (a > b) ? a : b;
	}
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


	Node* insertNode(Node* root, int value) {
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
	Node* minValueNode(Node* node) {
		Node* current = node;

		while (current->left != nullptr)
			current = current->left;

		return current;
	}

	Node* deleteNode(Node* root, int key) {
		if (root == nullptr)    return root;

		if (key < root->data)
			root->left = deleteNode(root->left, key);

		else if (key > root->data)
			root->right = deleteNode(root->right, key);

		else {
			if ((root->left == nullptr) || (root->right == nullptr)) {
				Node* temp = root->left ? root->left : root->right;

				if (temp == nullptr) {
					temp = root;
					root = nullptr;
				}
				else *root = *temp;
				free(temp);
			}
			else {
				Node* temp = minValueNode(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
		}

		if (root == nullptr)    return root;

		root->height = 1 + max(height(root->left), height(root->right));

		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0)
			return rightRotate(root);

		if (balance > 1 && getBalance(root->left) < 0) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		if (balance < -1 && getBalance(root->right) <= 0)
			return leftRotate(root);

		if (balance < -1 && getBalance(root->right) > 0) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
		return root;
	}
	void preOder(Node* root) {
		if (root != nullptr) {
			cout << root->data << " ";
			preOder(root->left);
			preOder(root->right);
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

};

int main() {
	AVL tree;
	tree.insertNode(20);
	tree.insertNode(15);
	tree.insertNode(25);
	tree.preOder();
	cout << endl;
	tree.print2DUtil();

	cout << endl << endl;
	tree.insertNode(30);
	tree.preOder();
	cout << endl;
	tree.print2DUtil();

	cout << endl << endl;
	tree.insertNode(45);
	tree.preOder();
	cout << endl;
	tree.print2DUtil();

	cout << endl << endl;
	tree.insertNode(40);
	tree.preOder();
	cout << endl;
	tree.print2DUtil();

	cout << endl << endl;
	tree.insertNode(35);
	tree.preOder();
	cout << endl;
	tree.print2DUtil();

	cout << endl << endl;
	tree.deleteNode(30);
	tree.preOder();
	cout << endl;
	tree.print2DUtil();

	cout << endl << endl;
	tree.deleteNode(25);
	tree.preOder();
	cout << endl;
	tree.print2DUtil();

	cout << endl << endl;
	tree.deleteNode(40);
	tree.preOder();
	cout << endl;
	tree.print2DUtil();
}