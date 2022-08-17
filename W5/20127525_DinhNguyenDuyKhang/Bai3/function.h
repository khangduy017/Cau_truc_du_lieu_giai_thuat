#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_
#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
void printLinkList(Node* head);
void addNodeBack(Node*& head, int value);
void selectionSort(Node* head);
#endif // !_FUNCTION_
