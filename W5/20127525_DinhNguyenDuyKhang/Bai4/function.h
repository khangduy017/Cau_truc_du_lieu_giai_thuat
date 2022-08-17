#pragma once
#include<iostream>
using namespace std;

class DoublyLinkedList{
public:
	struct Node	{
		int data;
		Node* front, * back;
	};
	DoublyLinkedList();
	void push(int);
	void display();
	void searchPush(Node*&, Node*);
	void insertionSort();
	~DoublyLinkedList();

private:
	Node* creatNode(int);
	Node* head;
};
