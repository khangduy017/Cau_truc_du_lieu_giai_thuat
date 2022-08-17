#include"function.h"

int main() {
	int a[100];
	int n;
	do {
		cout << "Nhap vao so phan tu : ";
		cin >> n;
		if (n <= 0) cout << "Nhap khong hop le!!! Vui long nhap lai\n";
	} while (n <= 0);
	cout << "Nhap vao phan tu : ";
	for (int i = 0; i < n; i++) {
		do {
			cin >> a[i];
			if (a[i] <= 0) cout << "Nhap phan tu duong !!!\n";
		} while (a[i] <= 0);
	}
	func(a, n);
	
	cout << "Mang sau khi sap xep : ";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
}