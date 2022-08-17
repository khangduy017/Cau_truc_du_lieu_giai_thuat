#include"function.h"

int main() {
	Node* root;
	root = nullptr;

	insert(root, 11);
	insert(root, 6);
	insert(root, 19);
	insert(root, 4);
	insert(root, 9);
	insert(root, 16);
	insert(root, 27);
	insert(root, 13);
	insert(root, 24);
	insert(root, 2);
	insert(root, 7);
	insert(root, 10);

	cout << "Ancestor of two node: " << findAncestor(root, 9, 16) << endl;
}