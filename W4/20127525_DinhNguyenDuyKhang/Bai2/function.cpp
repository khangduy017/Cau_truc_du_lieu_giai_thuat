#include"function.h"

void push(int*& c,int &n, int value) {
	int* b = new int[n];
	for (int i = 0; i < n; i++) b[i] = c[i];

	delete[] c;
	c = new int[n + 1];
	for (int i = 1; i <= n; i++) c[i] = b[i - 1];
	c[0] = value;
	n++;
	delete[] b;
}

void pop(int*& c,int &n) {
	int* b = new int[n];
	for (int i = 0; i < n; i++) b[i] = c[i];

	delete[] c;
	c = new int[n - 1];
	for (int i = 0; i < n - 1; i++) c[i] = b[i];
	n--;
	delete[] b;
}

int size(int*& a, int &n) {
	return n;
}

int value(int*& c,int &n) {
	return c[n - 1];
}

bool empty(int* c, int &n) {
	if (n == 0) return true;
	return false;
}

bool full(int* c,int &n) {
	if (n >= 500) return true;
	return false;
}