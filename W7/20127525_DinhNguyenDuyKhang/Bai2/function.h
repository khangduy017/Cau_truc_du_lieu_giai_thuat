#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
	int height;
};

void insertNode(Node*& root, int value);
string checkAVL(Node* root);

#endif // !_FUNCTION
