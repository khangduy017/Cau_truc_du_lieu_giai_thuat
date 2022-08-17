#include"function.h"

void selectionSort(Node* head){
	Node* temp = head;
	while (temp) {
		Node* min = temp;
		Node* r = temp->next;
		while (r) {
			if (min->data > r->data) min = r;
			r = r->next;
		}
		swap(temp->data, min->data);
		temp = temp->next;
	}
}

void printLinkList(Node* head) {
	if (head == NULL) cout << "Empty !";
	else {
		while (head != nullptr) {
			cout << head->data << " ";
			head = head->next;
		}
	}
}

void addNodeBack(Node*&head, int n) {
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		Node* p = new Node;
		p->data = value;
		p->next = nullptr;
		if (head == nullptr) {
			head = p;
		}
		else {
			Node* tmp = head;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = p;
		}
	}
}














