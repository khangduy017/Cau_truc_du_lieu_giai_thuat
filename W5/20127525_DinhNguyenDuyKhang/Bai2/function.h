#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_
#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void printListLink(Node* head);
void push(Node*& head, int value);
void pop(Node*& head);
int sizeOfMemory(Node* head);

#endif // !_FUNCTION_
