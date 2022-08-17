#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct Node {
	string data;
	Node* left,*right;
};
void insertNode(Node*& root,string value);


#endif // !_FUNCTION_
