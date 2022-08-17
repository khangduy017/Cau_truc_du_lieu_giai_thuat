#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_
#include<iostream>
#include<string>
#include<stack>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
};

void insertNode(Node*& root, int value);
void PreOrderNode(Node* root);
void PostOrderNode(Node* root);
void Delete(Node*& root, int x);
bool SumOfNode(Node* root2, int value);

#endif // !_FUNCTION_