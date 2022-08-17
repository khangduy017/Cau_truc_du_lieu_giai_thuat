#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
template <class Item >
void compare_swap(Item& x, Item& y) {
	if (x > y) swap(x, y);
}
//template <class Item >
//void bubble(Item a[], int l, int r) {
//	for (int i = l; i < r; i++)
//		for (int j = r; j > i; j--)
//			compare_swap(a[j - 1], a[j]);
//}
void bubble_sort_re(int a[], int l, int r) {
	if (r <= l)
		return;

	for (int i = l; i < r; i++)
		if (a[i] > a[i + 1])
			swap(a[i], a[i + 1]);

	bubble_sort_re(a, l, r - 1);
}
template <class Item >
void bubble(Item a[], int l, int r) {
	if (l > r)
		return;
	bool sort = true;
	for (int j = r; j > l; j--)
		if (a[j - 1] > a[j]) {
			swap(a[j], a[j - 1]);
			sort = false;
		}
	if (!sort) bubble(a, l + 1, r);
}
int main() {
	int a[] = { 1, 3, 8, 2, 9, 2, 5, 6 };
	int n = 8;
	int l = 0, r = n - 1;
	bubble(a, l, r);
	for (auto e : a)
		cout << e << " ";
}
