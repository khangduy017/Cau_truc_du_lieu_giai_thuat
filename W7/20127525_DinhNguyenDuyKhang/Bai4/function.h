#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
	int height;
};

void insert(Node*& root, int data);
int findAncestor(Node* root, int a, int b);

#endif // !_FUNCTION