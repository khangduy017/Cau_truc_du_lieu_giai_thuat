#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

void countingSort(int a[], int n) {
	// tìm phần tử lớn nhất của mảng
	int maxVal = *max_element(a, a + n - 1);

	// count dùng để lưu số lần xuất hiện 
	// của phần tử từ phần tử nhỏ nhất đến lớn nhất
	// pos dùng để lưu vị trí của phần tử ở trong mảng sau khi sắp xếp
	int* count = new int[maxVal + 1], * pos = new int[maxVal + 1];

	// memset dùng để gáng các phần tử của count đều có giá trị 0
	memset(count, 0, (maxVal + 1) * sizeof(count));

	// count bắt đầu gán số lần xuất hiện của phần tử ( chỉ cần những phần tử
	// có xuất hiện trong mảng nên i chỉ chạy đến right vì các phần tử còn lại
	// đã được gáng bằng giá trị 0).
	for (int i = 0; i < n; i++) count[a[i]]++;

	// gán pos[0] = count[0] để thực hiện dòng for bên dưới
	pos[0] = count[0];
	// mảng pos lưu vị trí mới  của phần tử 
	// (là phần tử cuối cùng nếu có những phẩn tử trùng nhau)
	for (int i = 1; i <= maxVal; i++) pos[i] = pos[i - 1] + count[i];

	int* b = new int[n];
	// gáng a[i] vào b[i] lưu vị trí chính xác
	for (int i = n - 1; i >= 0; i--) {
		b[pos[a[i]] - 1] = a[i];
		pos[a[i]]--;
	}

	for (int i = 0; i < n; i++) a[i] = b[i];
	delete[] b; delete[] count; delete[] pos;
}

void counting_sort_chr(string c[], int left, int right){
	map<string, int> count, pos;

	for (int i = left; i <= right; ++i) count[c[i]]++;
	count["abc"] = 2;

	string prev = ""; // i-1
	for (auto e : count) {
		string i = e.first;

		if (!prev.empty()) pos[i] = pos[prev] + count[i];
		else pos[i] = count[i];
		prev = e.first; // prev = i - 1
	}

	string ch[9];
	for (int i = right; i >= 0; --i) {
		ch[pos[c[i]] - 1] = c[i];
		pos[c[i]]--;
	}

	for (int i = 0; i <= right; ++i) c[i] = ch[i];
	for (int i = 0; i <= right; ++i) cout << c[i] << " ";
}


int main() {
	int a[]{ 1,5,76,12,56,190,1000,45 };
	int n = 8;
	string c[]{ "lan", "an" , "won", "rooney" , "beta", "cramped" , "chinh", "chinh" , "khoa" };
	countingSort(a, n);
	for (auto c : a) cout << c << " ";

}