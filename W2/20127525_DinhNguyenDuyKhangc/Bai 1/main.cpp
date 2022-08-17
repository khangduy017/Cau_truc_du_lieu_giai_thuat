#include"function.h"

int main() {
	srand(time(NULL));
	int n;
	cout << "Nhap vao so phan tu cua mang : ";
	cin >> n;
	int a[50000],b[50000];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
		b[i] = a[i];
	}
	
	showInsertion(a, n);
	showMerge(b, n);

}