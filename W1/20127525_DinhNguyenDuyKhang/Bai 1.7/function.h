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

void writefile(const char* filename, SinhVien sv);

#endif // !_FUNCTION_
