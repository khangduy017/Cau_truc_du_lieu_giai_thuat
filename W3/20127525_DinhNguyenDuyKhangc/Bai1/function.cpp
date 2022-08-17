#include"function.h"


vector<int> linearSearch(int arr[], int n, int x) {
	vector<int> m;
	for (int i = 0; i < n; i++)
		if (arr[i] == x)
			m.push_back(i);
	return m;
}

vector<int> sentinelSearch(int arr[], int n, int x) {
	vector<int> m;
	int last = arr[n - 1];
	arr[n - 1] = x;
	int i = 0;

	while (i < n) {
		while (arr[i] != x) {
			i++;
		}
		m.push_back(i);
		i++;
	}
	arr[n - 1] = last;
	if (arr[n - 1] != x)
		m.pop_back();
	return m;
}

void QuickSort(int m[], int left, int right) {
	if (left >= right) return;
	int pivot = m[(left + right) / 2];
	int i = left, j = right;
	do {
		while (m[i] < pivot) i++;
		while (m[j] > pivot) j--;
		if (i <= j)
		{
			swap(m[i], m[j]);
			i++;
			j--;
		}
	} while (i < j);
	QuickSort(m, left, j);
	QuickSort(m, i, right);
}

vector<int> binSearch(int arr[], int n, int x) {
	int left = 0, right = n - 1;
	int mid;
	vector<int> m;
	do {
		mid = (left + right) / 2;
		if (x == arr[mid]) {
			for (int i = mid - 1; i >= 0 && arr[i] == x; i--)
				m.insert(m.begin(), i);
			m.push_back(mid);
			for (int i = mid + 1; i < n && arr[i] == x; i++)
				m.push_back(i);
			break;
		}
		else if (x < arr[mid]) {
			right = mid - 1;
		}
		else
			left = mid + 1;
	} while (left <= right);
	return m;
}



