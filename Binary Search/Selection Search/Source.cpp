#include<iostream>
#include<ctime>
using namespace std;

void ss(int a[], int n) {
	int min;
	for (int i = 0; i < n-1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min] > a[j]) min = j;
		}

		if (min != i) swap(a[i], a[min]);
	/*	for (int k = 0; k < n; k++) cout << a[k] << " ";
		cout << endl;*/
	}
}

void InputRand(int a[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] =-50+ rand() % 100;
	}
}
int main() {
	int n;
	cin >> n;
	int a[100];
	InputRand(a, n);
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	ss(a, n);
	for (int i = 0; i < n; i++) cout << a[i] << " ";
}