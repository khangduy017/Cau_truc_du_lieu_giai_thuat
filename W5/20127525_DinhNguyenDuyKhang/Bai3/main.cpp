#include"function.h"

int main() {
	Node* head = new Node;
	head = nullptr;
	int n;
	cout << "Enter the number of node: ";
	cin >> n;
	cout << "Enter elements \n";
	addNodeBack(head, n);
    selectionSort(head);
	cout << endl;
	cout << "LinkedList after arange: ";
	printLinkList(head);
}