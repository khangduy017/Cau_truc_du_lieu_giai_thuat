#include<iostream>
using namespace std;


void merge(int a[], int aux[], int l, int m, int r) {
	
	int i, j, k;
	
	for (int k = l; k <= r; k++) aux[k] = a[k];
	
	i = l; j = m + 1; k = l;
	while (i <= m && j <= r)
		if (aux[i] <= aux[j]) a[k++] = aux[i++];
		else				  a[k++] = aux[j++];

	while (i <= m) a[k++] = aux[i++];
	while (j <= r) a[k++] = aux[j++];
}

// recursion
// hàm mergesort này dùng để chia nhỏ mảng đến từng phần tử 
// sau đó thì sắp xếp 2 4 8... phần tử theo thứ tự tăng dần 
// bởi hàm merge rồi gáng lại vào mảng a và ghép lại theo thứ tự 
void mergesort(int a[], int aux[], int l, int r) {
	if (r <= l) return;
	int m = (l + r) / 2;
	mergesort(a, aux, l, m);
	mergesort(a, aux, m + 1, r);
	if (a[m] > a[m + 1]) merge(a, aux, l, m, r);
}




void merge2(int dest[], int src[], int l, int m, int r) {
	int i, j, k;
	i = l; j = m + 1; k = l;
	while (i <= m && j <= r)
		if (src[i] <= src[j]) dest[k++] = src[i++];
		else dest[k++] = src[j++];
	while (i <= m)
		dest[k++] = src[i++];
	while (j <= r)
		dest[k++] = src[j++];
}

//norecursion
//
void merge(int a[], int aux[], int l, int m, int r) {
	int i, j, k;
	for (int k = l; k <= r; k++) aux[k] = a[k];
	i = l; j = m + 1; k = l;
	while (i <= m && j <= r)
		if (aux[i] <= aux[j]) a[k++] = aux[i++];
		else a[k++] = aux[j++];

	while (i <= m) a[k++] = aux[i++];
	while (j <= r) a[k++] = aux[j++];
}
void mergesort2(int dest[], int src[], int l, int r) {
	for (int sz = 1; sz <= r; sz += sz)
		for (int i = l; i <= r - sz; i += sz + sz) {
			merge(dest, src, i, i + sz - 1, min(i + sz + sz - 1, r));
		}
		swap(src, dest);
}


int main() {
	int a[100] = { 5,3,6,8,7,90,1,2 };
	int aux[100];
	int n = 8;
	mergesort2(a, aux, 0, n-1	);
	for (int i = 0; i < n; i++) cout << a[i] << " ";
}