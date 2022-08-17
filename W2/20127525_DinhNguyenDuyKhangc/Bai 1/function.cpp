#include"function.h"

void merge(int a[], int aux[], int l, int m, int r) {
	int i, j, k;
	for (k = l; k <= r; k++)
		aux[k] = a[k];
	i = l; j = m + 1; k = l;
	while (i <= m && j <= r)
		if (aux[i] <= aux[j]) a[k++] = aux[i++];
		else a[k++] = aux[j++];
	while (i <= m)
		a[k++] = aux[i++];
	while (j <= r)
		a[k++] = aux[j++];
}

void mergesort(int a[], int aux[], int l, int r) {
	if (r <= l) return;
	int m = (l + r) / 2;
	mergesort(a, aux, l, m);
	mergesort(a, aux, m + 1, r);
	if (a[m] > a[m + 1]) merge(a, aux, l, m, r);
}


void insertionSort(int arr[], int n) {
	int key;
	for (int i = 1; i < n; i++) {
		key = arr[i];
		int j = i - 1;
		for (; j >= 0 && arr[j] > key; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
}

void showInsertion(int a[], int n) {
	clock_t start, end;
	double time;

	start = clock();
	insertionSort(a, n);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;

	cout << "\nThoi gian chay InsertionSort(n): " << time << "s";
}

void showMerge(int a[], int n) {
	int aux[50000];
	clock_t start, end;
	double time;

	start = clock();
	mergesort(a, aux, 0, n - 1);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;

	cout << "\nThoi gian chay MergeSort(n): " << time << "s";
}