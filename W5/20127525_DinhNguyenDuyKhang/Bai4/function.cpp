#include"function.h"

DoublyLinkedList::DoublyLinkedList() {
	head = nullptr;
}

DoublyLinkedList::Node* DoublyLinkedList::creatNode(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->back = newNode->front = nullptr;
	return newNode;	
}
void DoublyLinkedList::push(int data) {
	if (head == nullptr) {
		head = creatNode(data);
	}
	else {
		Node* tmp = head;
		Node* newNode = creatNode(data);
		while (tmp->back) tmp = tmp->back;
		newNode->front = tmp;
		tmp->back = newNode;
	}
}

void DoublyLinkedList::searchPush(Node*& newHead, Node* current) {
	if (newHead == nullptr)(newHead) = current;
	else if (current->data <= (newHead)->data) {
		current->back = (newHead);
		current->back->front = current;
		(newHead)=current;
	}
	else {
		Node* tmp = (newHead);
		while (tmp->back&& tmp->back->data< current->data) tmp = tmp->back;
		current->back = tmp->back;
		if (tmp->back != nullptr) current->back->front = tmp;
		tmp->back = current;
		current->front = tmp;
	}
}

void DoublyLinkedList::insertionSort() {
	Node* curr = head, *newHead = nullptr;
	while (curr) {
		Node* next = curr->back;
		curr->back = nullptr;
		curr->front = nullptr;
		searchPush((newHead),curr);
		curr = next;
	}
	head = newHead;	
}
void DoublyLinkedList::display() {
	Node* tmp = head;
	while (tmp) {
		cout << tmp->data << " ";
		tmp = tmp->back;
	}
}
DoublyLinkedList::~DoublyLinkedList() {

}