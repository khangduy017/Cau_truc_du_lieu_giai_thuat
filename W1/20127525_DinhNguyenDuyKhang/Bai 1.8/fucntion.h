#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

struct SinhVien {
	char name[50];
	int age;
	char address[100];
};

void Infile(const char* filename, vector<SinhVien>& s);

#endif // !_FUNCTION_
