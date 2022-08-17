#include"function.h"

void inputArray(int a[][10], int m, int n, int b[],int &ind) {
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			b[ind] = a[i][j];
			ind++;
		}
	}
}

void handlingArray(int a[][10], int m, int n, int b[], int ind) {
	
	for (int i = 0; i < ind - 1; i++) {
		for (int j = i + 1; j < ind; j++) {
			if (b[i] > b[j]) swap(b[i], b[j]);
		}
	}

	int dem = 0, i = 0, j = 1, k = 2;
	while (true) {
		for (int l = i; l < n; l++)
			a[i][l] = b[dem++];

		if (dem == ind) break;
		for (int l = i + 1; l < m; l++)
			a[l][n - j] = b[dem++];

		if (dem == ind) break;
		for (int l = n - k; l >= i; l--)
			a[m - j][l] = b[dem++];

		if (dem == ind) break;
		for (int l = m - k; l > i; l--)
			a[l][i] = b[dem++];

		if (dem == ind) break;
		i++, n--, m--;
	}
}

void outputArray(int a[][10], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout <<"\n\n\n";
	}
}