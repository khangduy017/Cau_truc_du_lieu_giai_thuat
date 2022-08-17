#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void heapify(int a[], int n, int i) {
	
	int maxest = i;
	
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (r < n && a[r] > a[maxest])	maxest = r;
	if (l < n && a[l] > a[maxest]) 	maxest = l;
	// nếu maxest chưa là thằng nhỏ hoặc lớn nhất ở gốc thì tìm tiếp
	if (maxest != i) {
		// đổi chỗ nó với i trước đó do nó lớn hoặc nhỏ hơn i
		swap(a[i], a[maxest]);
		heapify(a, n, maxest);
	}
}

void heapSort(int a[], int n) {
	// xây dựng max-heap
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i);
	}
	// đã có max-heap
	for (int i = n - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		// xây dựng lại max-heap
		heapify(a, i, 0);
	}
}

int main(){
	//srand(time(NULL));
	//
	//int n;
	//cout << "Enter the number of elements: ";
	//cin >> n;
	//
	//int m[100000];
	//cout << "Random array: \n";
	//
	//for (int i = 0; i < n; i++)	m[i] = rand() % 100;
	//for (int i = 0; i < n; i++)	cout << m[i] << " ";
	//cout << endl;
	
	int m[]{ 7,2,6,1,9 };
	int n = 5;

	heapSort(m, n);
	
	for (int i = 0; i < n; i++) cout << m[i] << " ";
}

//
//srand(time(NULL));
//int res = rand() % (50 - 3 + 1) + 3;