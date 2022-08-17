#include"function.h"

void push(char*& a,int &n, char value) {
	char* b = new char[n];
	for (int i = n - 1; i >= 0; i--) {
		b[i] = a[i];
	}
	delete[] a;
	a = new char[n + 1];
	for (int i = n; i > 0; i--) {
		a[i] = b[i - 1];
	}
	a[0] = value;
	n++;
	delete[] b;
}

void pop(char*& a,int &n) {
	char* b = new char[n];
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	delete[] a;
	a = new char[n - 1];
	for (int i = 0; i < n - 1; i++) {
		a[i] = b[i + 1];
	}
	n--;
	delete[] b;
}


int size(char*& a, int &n) {
	return n;
}


char top(char*& a) {
	return a[0];
}

bool empty(char* a, int &n) {
	if (n == 0)	return true;
	return false;
}

bool full(char* a, int &n) {
	if (n >= 500) return true;
	return false;
}