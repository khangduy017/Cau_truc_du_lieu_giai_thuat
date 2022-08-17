#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void push(char*& a, int &n, char value);

void pop(char*& a, int &n);


int size(char*& a, int &n);


char top(char*& a);

bool empty(char* a, int &n);

bool full(char* a, int &n);

#endif // !_FUNCTION_
