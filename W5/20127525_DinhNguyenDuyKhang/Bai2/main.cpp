#include"function.h"

int main() {
	Node* head = new Node;
	head = NULL;

	push(head, 1);
	push(head, 2);
	push(head, 3);
	push(head, 4);
	push(head, 5);
	push(head, 7);
	push(head, 100);
	cout << "Size: " << sizeOfMemory(head) << endl;
	cout << "Queue: ";
	printListLink(head);
	cout << endl;

	pop(head);
	pop(head);
	pop(head);

	cout << "\nAfter pop :\n";
	cout << "Size: " << sizeOfMemory(head) << endl;
	cout << "Queue: ";
	printListLink(head);

	delete head;
}