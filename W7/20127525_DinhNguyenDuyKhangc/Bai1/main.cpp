#include"function.h"

int main() {
	Node* root;
	root = nullptr;

	Insert(root, 5);
	Insert(root, 8);
	Insert(root, 9);
	Insert(root, 15);
	Insert(root, 13);
	Insert(root, 20);
	Insert(root, 25);
	Insert(root, 30);
	
	cout << "Pre-order: ";
	PreOrderNode(root);
	cout << "\nIn-order: ";
	InOrderNode(root);
	cout << "\nPost-order: ";
	PostOrderNode(root);
	
	cout << "\n\nHeight: "<<height(root);

	Delete(root, 8);
	Delete(root, 20);
	cout << "\n\nAfter delete \n";
	cout << "Pre-order: ";
	PreOrderNode(root);
	cout << "\nIn-order: ";
	InOrderNode(root);
	cout << "\nPost-order: ";
	PostOrderNode(root);

	cout << "\n\nHeight: " << height(root);

	int x;
	cout << "\n\nEnter element need to check: ";
	cin >> x;
	if (search(root, x)) cout << "YES";
	else cout << "NO";
}