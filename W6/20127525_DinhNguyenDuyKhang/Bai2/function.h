#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Node {
		string id;
		string name;
		string birth;
		bool graduate;

		Node* left, * right;
};

void insertNode(Node*& root, string id, string name, string birth, bool graduate);
void searchNode(Node* root, string id);
void dislayList(Node* root);
void Delete(Node* root, string id);
void dislayGraduate(Node* root);
void checkFile(Node*& head, const char* filename);
void saveFile(Node* root, const char* filename);
#endif // !FUNCTION
