#include<iostream>
#include<stack>

using namespace std;


// chia đôi mảng, sau đó lần lượt tìm phần tử lớn hơn
// pivot bên trái và nhỏ hơn pivot ở bên phải sau đó
// đổi chỗ 2 phần tử đó, liên tục như vậy đến khi i<j thì
// mảng trở thành bên trái nhỏ hơn pivot, bên phải lớn hơn
// pivot sau đó gọi đệ qui tiếp tục qui trình chia đôi bên trái 
// và bên phải cho đến khi chia nhỏ chỉ còn 1 phần tử thì dừng đệ qui
void QuickSortMid(int* a, int left, int right) {
	if (left >= right) return;
	int pivot = a[(left + right) / 2];
	int i = left, j = right;
	
	while (i < j) {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	QuickSortMid(a, left, j);
	QuickSortMid(a, i, right);
}

// đầu tiên nó đánh dấu thằng đầu tiên (left), sau đó tìm thằng nhỏ hơn nó
// mà gần với nó nhất là a[i] để swap với thằng a[pos] là thằng kế bên nó,
// khi tìm được thằng nhỏ hơn thì pos sẽ tự ++ lên
// sau 1 vòng for thì nó sẽ swap left với cái pos thì nó sẽ thỏa tính chất
// bên trái nó nhỏ hơn nó, bên phải nó lớn hơn nó
void QuickSortHead(int* a, int left, int right) {
	if (left >= right) return;
	int pos = left;
	for (int i = left; i < right; ++i) {
		if (a[i] < a[left]) {
			pos++;
			swap(a[i], a[pos]);
		}
	}
	swap(a[left], a[pos]);

	QuickSortHead(a, left, pos);
	QuickSortHead(a, pos + 1, right);
}

void QuickSortTail(int* a, int left, int right) {
	if (left >= right) return;
	int pos = right;
	for (int i = right; i >= left; i--) {
		if (a[i] > a[right]) {
			pos--;
			swap(a[i], a[pos]);
		}
	}
	swap(a[right], a[pos]);

	QuickSortTail(a, left, pos-1);
	QuickSortTail (a, pos +1, right);
 }

int main() {
	int a[]{13, 56,0,17,34,1000,100,19,37,13 };
	QuickSortTail(a, 0, 9);
	for (int i = 0; i < 10; i++) cout << a[i] << " ";
}


//QuickSort noRecursion

//int partition(int a[], int l, int r) {
//	int i = l - 1, j = r; int v = a[r];
//	for (;;) {
//		while (a[++i] < v);
//		while (v < a[--j]) if (j == l) break;
//		if (i >= j) break;
//		swap(a[i], a[j]);
//	}
//	swap(a[i], a[r]);
//	return i;
//}
//
//void quicksort(int a[], int l, int r) {
//	stack<int> st;
//	st.push(l);
//	st.push(r);
//	while (!st.empty()) {
//		int i = partition(a, l, r);
//		if (l < i - 1) {
//			st.push(l);
//			st.push(i - 1);
//		}
//		if (i + 1 < r) {
//			st.push(i + 1);
//			st.push(r);
//		}
//		r = st.top(); st.pop();
//		l = st.top(); st.pop();
//	}
//}
//
//int main() {
//	int a[]{ 5,3,8,1,9,34,23 };
//	quicksort(a, 0, 6);
//	for (auto e : a) cout << e << " ";
//}