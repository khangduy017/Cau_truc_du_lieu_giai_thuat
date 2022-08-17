#include<iostream>
using namespace std;

void quicksort(int* a, int left, int right) {
	if (left >= right) return;

	int pivot = a[left];
	int pos_of_value = left;

	for (int i = left; i < right; i++) {
		if (pivot > a[i]) {
			++pos_of_value;
			swap(a[i], a[pos_of_value]);
		}
	}
	swap(a[left], a[pos_of_value]);
	for (int i = 0; i < 5; i++) cout << a[i] << " ";
	cout << endl;
	quicksort(a, left, pos_of_value);
	quicksort(a, pos_of_value + 1, right);
}

int main() {
	int a[] = { 4,7,6,2,1 };
	for (int i = 0; i < 5; i++) cout << a[i] << " ";
	cout << endl;
	quicksort(a, 0, 5);
	cout << "\n\n\n\n\n";
	for (int i = 0; i < 5; i++) cout << a[i] << " ";
}
