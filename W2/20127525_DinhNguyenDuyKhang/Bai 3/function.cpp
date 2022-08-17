#include"function.h"

void QuickSort(string a[], int b[],string id[], int left, int right) {
	if (left >= right) return;
	char pivot = a[(left + right) / 2][0];
	int i = left, j = right;

	while (i < j) {
		while (a[i][0] < pivot) i++;
		while (a[j][0] > pivot) j--;
		swap(a[i], a[j]);
		swap(b[i], b[j]);
		swap(id[i], id[j]);
		i++;
		j--;
	}
	QuickSort(a, b,id, left, j);
	QuickSort(a, b,id, i, right);
}

void merge(int a[], string b[],string id[], int aux[], string bux[],string iux[], int l, int m, int r) {
	int i, j, k;
	for (int k = l; k <= r; k++) {
		aux[k] = a[k];
		bux[k] = b[k];
		iux[k] = id[k];
	}
	i = l; j = m + 1; k = l;
	while (i <= m && j <= r)
		if (aux[i] <= aux[j]) {
			a[k] = aux[i];
			b[k] = bux[i];
			id[k] = iux[i];
			k++, i++;
		}
		else {
			a[k] = aux[j];
			b[k] = bux[j];
			id[k] = iux[j];
			k++, j++;
		}
	while (i <= m) {
		a[k] = aux[i];
		b[k] = bux[i];
		id[k] = iux[i];
		k++, i++;
	}
	while (j <= r) {
		a[k] = aux[j];
		b[k] = bux[j];
		id[k] = iux[j];
		k++, j++;
	}
}


void mergesort(int a[],string b[],string id[], int aux[],string bux[],string iux[], int l, int r) {
	if (r <= l) return;
	int m = (l + r) / 2;
	mergesort(a,b,id, aux,bux,iux, l, m);
	mergesort(a,b,id, aux,bux,iux, m + 1, r);
	if (a[m] > a[m + 1]) merge(a,b,id, aux,bux,iux, l, m, r);
}