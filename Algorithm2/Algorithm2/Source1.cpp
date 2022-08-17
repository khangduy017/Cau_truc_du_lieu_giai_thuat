#include<iostream>

using namespace std;

void insertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j;
		for (j = i - 1; j >= 0 && a[j] > key; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

void shellSort(int a[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int key = a[i];
			int j;
			for (j = i-gap; j >= 0 && a[j] > key; j-=gap) {
				a[j+gap] = a[j];
			}
			a[j+gap] = key;
		}
	}
}

void shellSort1(int a[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int key = a[i];
			int j;
			for (j = i - gap; j >= gap && a[j] > key; j -= gap) {
				a[j + gap] = a[j];
			}
			a[j + gap] = key;
		}
	}
}

void shellSortM(int arr[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int temp = arr[i];

			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}

	}
}

int main() {
	//int a[]{ 5,3,7,10,45,23 };
	//int n = 6;
	////insertionSort(a, n);
	////for (auto c : a) cout << c << " ";
	//int aux[50000];
	srand(time(NULL));
	int n;
	cout << "Nhap vao so phan tu cua mang : ";
	cin >> n;
	int a[50000], b[50000], c[50000];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
		b[i] = a[i];
		c[i] = a[i];
	}

	clock_t start1, end1;
	double time1;
	start1 = clock();
	shellSort1(a, n);
	end1 = clock();
	time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

	clock_t start2, end2;
	double time2;
	start2 = clock();
	shellSort(c, n);
	end2 = clock();
	time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

	clock_t start, end;
	double time;
	start = clock();
	shellSort(b, n);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;

	

	cout << "\nThoi gian chay MergeSort0(n): " << time << "s";
	cout << "\nThoi gian chay MergeSortGap(n): " << time1 << "s";
	cout << "\nThoi gian chay MergeSortM(n): " << time2 << "s";

}