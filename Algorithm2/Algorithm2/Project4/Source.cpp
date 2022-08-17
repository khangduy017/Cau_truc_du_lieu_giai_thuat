#include <iostream>
#include <string>
#include <stack>
using namespace std;
//void sieve(int N) {
//	int i;
//	int *a = new int[N];
//	for (i = 2; i < N; i++) a[i] = 1;
//	for (i = 2; i < N; i++)
//		if (a[i])
//			for (int j = i; i*j < N; j++) a[i*j] = 0;
//	for (i = 2; i < N; i++)
//		if (a[i]) cout << " " << i;
//	delete[] a;
//}
template <class Item >
int partition(Item a[], int l, int r) {
	swap(a[l], a[r]);
	int i = l - 1, j = r; Item v = a[r];
	for (;;) {
		while (a[++i] < v);
		while (v < a[--j]) if (j == l) break;
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	swap(a[i], a[r]);
	return i;
}
template <class Item >
void quicksort(Item a[], int l, int r) {
	stack<int> st;
	st.push(l);
	st.push(r);
	while (!st.empty()) {
		int i = partition(a, l, r);
		// call quicksort(a, l, i - 1);
		if (l < i - 1) {
			st.push(l);
			st.push(i - 1);
		}
		// call quicksort(a, i + 1, r);
		if (i + 1 < r) {
			st.push(i + 1);
			st.push(r);
		}
		// end function
		r = st.top(); st.pop();
		l = st.top(); st.pop();
	}
}
//template <class Item >
//void qsort(Item a[], int l, int r) {
//	if (l >= r) return;
//	int i = partition(a, l, r);
//	qsort(a, l, i - 1);
//	qsort(a, i + 1, r);
//}



int main() {
	int a[] = { 4, 5, 4, 2, 3, 5, 6, 0 };
	int n = 8;
	int l = 0, r = n - 1;
	quicksort(a, l, r);
	for (int e : a)
		cout << e << " ";
}


