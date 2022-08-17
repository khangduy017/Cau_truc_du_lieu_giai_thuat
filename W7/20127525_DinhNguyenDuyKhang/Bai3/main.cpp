#include"function.h"

int main() {
	Node* root;
	root = nullptr;

	//insert(root, 5);
	//insert(root, 9);
	//insert(root, 11);
	//insert(root, 3);
	//insert(root, 13);
	//insert(root, 20);
	//insert(root, 7);
	//insert(root, 17);
	//insert(root, 35);

	insert(root, 8);
	insert(root, 4);
	insert(root, 14);
	insert(root, 3);
	insert(root, 6);
	insert(root, 10);
	insert(root, 15);
	insert(root, 7);
	insert(root, 11);
	insert(root, 16);


	cout << checkAVL(root)<<endl;
}