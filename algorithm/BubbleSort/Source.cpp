#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// i chạy từ left đến right
// j chạy từ right về i, sau dòng for này phần tử nhỏ nhất được đẩy lên đầu tiên
// sau đó i tăng lên, j tiếp tục chạy tương tự tìm được phần tử nhỏ nhất tiếp theo
// đứng sau phần tử nhỏ nhất đầu tiên
void bubble(int a[], int l, int r) {
	for (int i = l; i < r; i++)
		for (int j = r-1; j > i; j--)
			if (a[j - 1] > a[j]) swap(a[j - 1], a[j]);
}


// sau lần chạy đầu tiên phần tử lớn nhất sẽ đứng ở cuối cùng
// sau lần đệ qui đó giảm right lại và chạy tương tự sẽ tìm được 
// phần tử lớn thứ 2 đứng sau phần tử nhất thứ nhất
void bubble_re1(int a[], int l, int r) {
	if (r <= l) return;

	for (int i = l; i < r; i++)
		if (a[i] > a[i + 1])	swap(a[i], a[i + 1]);

	bubble_re1(a, l, r - 1);
}


void bubble_re2(int a[], int l, int r) {
	if (l > r)
		return;
	bool sort = true;
	for (int j = r; j > l; j--)
		if (a[j - 1] > a[j]) {
			swap(a[j], a[j - 1]);
			sort = false;
		}
	if (!sort) bubble_re2(a, l + 1, r);
}

int main() {
	int a[100] = { 3,1,2,5,4 };
	bubble(a, 0, 5);
	for (int i = 0; i < 5; i++) cout << a[i] << " ";
}