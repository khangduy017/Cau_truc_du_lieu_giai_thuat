#include"function.h"

int main() {
	Node* root = nullptr;

	insertNode(root, 25);
	insertNode(root, 32);
	insertNode(root, 14);
	insertNode(root, 21);
	insertNode(root, 19);
	insertNode(root, 17);
	insertNode(root, 23);
	
	cout << "LRN: ";
	PostOrderNode(root);
	cout << "\nNLR: ";
	PreOrderNode(root);

	int f;
	cout << "\n\nNhap vao gia tri can xoa: ";
	cin >> f;
	Delete(root, f);

	cout << "\nNLR sau khi xoa: ";
	PreOrderNode(root);
	
	int k;
	cout << "\n\nNhap vao gia tri k: ";
	cin >> k;
	if (SumOfNode(root, k)) cout << "True";
	else cout << "False";
}