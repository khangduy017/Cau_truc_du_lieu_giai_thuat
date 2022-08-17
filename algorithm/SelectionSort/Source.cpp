#include<iostream>

using namespace std;

// gáng từng vị trí là min, chọn phần tử nhỏ nhất sau vị trí min 
// và thay thế phần tử đó với phần tử gáng là min ban đầu, từng 
// phần tử nhỏ nhất sẽ được đem lên đầu theo thứ tự tăng dần
// ngược lại với giảm dần.
void SelectionSort(int a[], int n) {
	int min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) 
			if (a[j] < a[min]) 	min = j;

		if (a[min] < a[i]) swap(a[min], a[i]);
	}
}

int main() {
	int a[]{ 56,101,3,4,12,66,34,12,4 };
	int n = 9;
	SelectionSort(a, n);
	for (auto c : a) cout << c << " ";
}