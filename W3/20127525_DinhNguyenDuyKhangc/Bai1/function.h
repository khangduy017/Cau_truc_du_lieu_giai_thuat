#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<stdlib.h>
#include<fstream>
using namespace std;

vector<int> linearSearch(int arr[], int n, int x);
vector<int> sentinelSearch(int arr[], int n, int x);
vector<int> binSearch(int arr[], int n, int x);
void QuickSort(int m[], int left, int right);


#endif // !_FUNCTION_