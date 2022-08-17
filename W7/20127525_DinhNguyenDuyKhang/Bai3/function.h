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

void insert(Node*& root, int data);
string checkAVL(Node* root);

#endif // !_FUNCTION