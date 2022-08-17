#include"function.h"


int main() {
	int m, n, ind = 0;
	cout << "Input rows and columns : ";
	cin >> m >> n;
	int a[10][10], b[101];
	cout << "Enter element of array : ";
	inputArray(a, m, n, b, ind);
	cout << "Array : \n";
	outputArray(a, m, n);
	handlingArray(a, m, n, b, ind);
	cout << "Array after sorting : \n\n";
	outputArray(a, m, n);

}