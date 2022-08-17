#include"function.h"

void printListLink(Node* head) {
	if (head == NULL) cout << "Empty !";
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

void push(Node*& head, int value) {
	Node* p = new Node;
	p->data = value;
	if (head == NULL) {
		p->next = NULL;
		head = p;
	}
	else {
		Node* c = head;
		while (c->next != NULL) {
			c = c->next;
		}
		c->next = p;
		p->next = NULL;
	}
}

void pop(Node*& head) {
	if (head == nullptr);
	else head = head->next;
}

int sizeOfMemory(Node* head) {
	int sum = 0;
	while (head != NULL) {
		sum++;
		head = head->next;
	}
	return sum;
}

