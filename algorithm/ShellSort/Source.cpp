#include<iostream>

using namespace std;

void shellSort(int a[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i - gap; j >= 0 && a[j] > temp; j -= gap) {
                a[j + gap] = a[j];
            }
            a[j + gap] = temp;
        }
    }
}

int main() {
    int a[]{ 56,101,3,4,12,66,34,12,4 };
    int n = 9;
    shellSort(a, n);
    for (auto c : a) cout << c << " ";
}