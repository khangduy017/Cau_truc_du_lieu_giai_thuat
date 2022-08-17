#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_

#include<iostream>
using namespace std;

struct Node {
	Node* left;
	Node* right;
	int data;
	int height;
};

int height(Node* root);
Node* rightRotate(Node* root);
Node* leftRotate(Node* root);
void Insert(Node*& root, int value);
void Delete(Node*& root, int value);
void PreOrderNode(Node* root);
void InOrderNode(Node* root);
void PostOrderNode(Node* root);
bool search(Node* root, int value);
#endif // !_FUNCTION_
