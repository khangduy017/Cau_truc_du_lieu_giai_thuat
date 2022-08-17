#include<iostream>

using namespace std;

// chọn phần tử a[i] làm key từ i=1 đến n
// sau đó so sánh key với những phần tử bên trái
// sau khi xong 1 vòng for key sẽ về đúng vị trí của nó
// tiếp tục như vậy từng phần tử sẽ được đẩy về đúng vị
// trí của nó từ bên phải


void insertionSort(int arr[], int n){
    int key, j;
    for (int i = 1; i < n; i++){
        key = arr[i];
        int j = i - 1;
        for(; j >= 0 && arr[j] > key;j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}


int main() {   
	int a[]{ 342,12,5,67,34,1};
	int n = 6;
	insertionSort(a, n);
	for (int i = 0; i < n; i++) cout << a[i] << " ";
}