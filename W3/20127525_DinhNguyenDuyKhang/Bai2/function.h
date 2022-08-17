#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_
#include<iostream>
#include<queue>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;

int SearchStr(string* a, int n, string word);

void infile(const char* filename, string* key, string* value, int& n);
#endif // !_FUNCTION_
