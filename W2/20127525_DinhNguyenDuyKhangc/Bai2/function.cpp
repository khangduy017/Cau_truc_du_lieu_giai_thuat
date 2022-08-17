#include"function.h"

void func(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			for (int j = i + 1; j < n; j++)
				if (a[j] % 2 == 0 && a[i] > a[j]) swap(a[i], a[j]);
		}
		else {
			for (int j = i + 1; j < n; j++)
				if (a[j] % 2 != 0 && a[i] < a[j]) swap(a[i], a[j]);
		}
	}
}