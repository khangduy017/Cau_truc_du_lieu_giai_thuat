#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void readFile(const char* filename, string name[], string num[], int& n);
void printHash(string hash[][2], int n);
void add(string hash[][2], string name[], string num[], int &size);
void find(string hash[][2], string name, int size);
void Delete(string hash[][2], string name, int &size);
void update(string hash[][2], string name, int size);
#endif // !_FUNCTION_
