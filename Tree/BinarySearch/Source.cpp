#include<iostream>
using namespace std;

void sortIn(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}

	}

}

void BinSearch(int a[], int n, int x) {
	int left = 0, right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x) {
			cout << x << " in array !!!";
			break;
		}
		else if (x < a[mid]) right--;
		else left++;
	}
	if (left > right) cout << "No value in array !!!";
}



int main() {
	int a[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	sortIn(a, n);
	BinSearch(a, n, 0);
}