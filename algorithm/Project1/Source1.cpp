#include<iostream>
using namespace std;

void quicksort(int* a, int left, int right) {
	if (left >= right) return;
	int pivot = a[(left + right) / 2];
	int i = left, j = right;

	while (i < j) {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		swap(a[i], a[j]);
		i++;
		j--;
	}
	quicksort(a, left, j);
	quicksort(a, i, right);
}

int main() {
	int a[]{ 10,20,5,1,4 };
	quicksort(a, 0, 4);
	for (int i = 0; i < 5; i++) cout << a[i] << " ";
}