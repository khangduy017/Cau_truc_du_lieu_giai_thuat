#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;


void push(int*& c, int& n, int value);

void pop(int*& c, int& n);

int size(int*& a, int& n);

int value(int*& c, int& n);

bool empty(int* c, int& n);
bool full(int* c, int& n);

#endif // !_FUNCTION_
