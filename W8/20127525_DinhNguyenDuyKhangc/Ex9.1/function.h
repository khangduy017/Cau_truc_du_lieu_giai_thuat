#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_
#include<iostream>
#include<vector>
using namespace std;

void Insert1(vector<int> hash[], int value, int size);
bool Search1(vector<int> hash[], int value, int size);

void Insert2(int hash[], int value, int size, int check);
bool Search2(int hash[], int value, int size);

void Insert3(int hash[], int value, int size, int check);
bool Search3(int hash[], int value, int size);

void Insert4(int hash[], int value, int size, int check);
bool Search4(int hash[], int value, int size);

#endif // !_FUNCTION_
