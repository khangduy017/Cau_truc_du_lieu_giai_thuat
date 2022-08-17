#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_
#include<iostream>
#include<string>
#include<stack>
using namespace std;

typedef struct tagSINHVIEN {
	int MSSV;
	char TenSV[100];
	float DTB;
} SINHVIEN;
typedef struct tagNODE {
	SINHVIEN SV;
	struct tagNODE* pNext;
};

void add(tagNODE*& root, SINHVIEN sv);
void printDTB(tagNODE* root);
void deleteNode(tagNODE*& root, int value);
void printSV(tagNODE* root, int mssv);
void deleteLL(tagNODE*& root);

#endif // !_FUNCTION_
