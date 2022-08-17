#include"function.h"

int main() {
	Node* head = new Node;
	head = NULL;

	push(head, 1);
	push(head, 2);
	push(head, 3);
	push(head, 4);
	push(head, 5);
	
	cout <<"Size: "<< sizeOfMemory(head)<<endl;
	cout << "Stack: ";
	print(head);
	cout << endl;

	pop(head);
	pop(head);
	pop(head);

	cout << "\nAfter pop :\n";
	cout << "Size: " << sizeOfMemory(head) << endl;
	cout << "Stack: ";
	print(head);

	delete head;
}