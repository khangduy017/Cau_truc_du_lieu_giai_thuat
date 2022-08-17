#include<iostream>
using namespace std;
#include<stack>

int partition(int a[], int l, int r) {
	int i = l - 1, j = r; int v = a[r];
	for (;;) {
		while (a[++i] < v);
		while (v < a[--j]) if (j == l) break;
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	swap(a[i], a[r]);
	return i;
}

void quicksort(int a[], int l, int r) {
	stack<int> st;
	st.push(l);
	st.push(r);
	while (!st.empty()) {
		int i = partition(a, l, r);
		if (l < i - 1) {
			st.push(l);
			st.push(i - 1);
		}
		if (i + 1 < r) {
			st.push(i + 1);
			st.push(r);
		}
		r = st.top(); st.pop();
		l = st.top(); st.pop();
	}
}

int main() {
	int a[]{ 5,3,8,1,9,34,23 };
	quicksort(a, 0, 6);
	for (auto e : a) cout << e << " ";
}