#include<iostream>

using namespace std;

void bubbleSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		for (int j = n - 1; j >= i; j--) {
			if (a[j - 1] > a[j]) swap(a[j - 1], a[j]);
		}
	}
}

void bubbleSortRe(int a[], int n) {
	if (n <= 1) return;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) swap(a[i], a[i - 1]);
	}

	bubbleSortRe(a, n - 1);
}

int main() {
	int a[]{ 1,1,60,2,94,151,1,2,14,195,14 };
	int n = 11;

	bubbleSortRe(a, n);
	for (auto c : a) cout << c << " ";

}