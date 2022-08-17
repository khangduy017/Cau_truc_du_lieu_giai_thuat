#include<iostream>

using namespace std;

void merge(int a[], int aux[], int l, int m, int r) {

	for (int i = l; i <= r; i++) aux[i] = a[i];

	int i = l, j = m+1, k = l;
	while (i<=m && j<=r) {
		if (aux[i] > aux[j]) a[k++] = aux[j++];
		else a[k++] = aux[i++];
	}
	while (i <= m) a[k++] = aux[i++];
	while (j <= r) a[k++] = aux[j++];
}

void mergeSort(int a[],int aux[], int l, int r) {
	if (l >= r) return;
	int m = (l + r) / 2;
	mergeSort(a,aux, l, m);
	mergeSort(a,aux, m + 1, r);
	if (a[m] > a[m + 1]) merge(a, aux, l, m, r);
}
int main() {
	int a[]{ 1,4,2,7,4555,3,1,56,23,78 };
	int n = 10;
	int aux[100];
	//insertionSort(a, n);
	mergeSort(a, aux, 0, n - 1);
	for (auto c : a) cout << c << " ";
}