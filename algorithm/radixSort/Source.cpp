#include<iostream>
#include <map>
#include<queue>
using namespace std;


int main() {
	int a[]{ 24,254,51,10,3 };
	int n = 5, max_val = a[0];

	for (int i = 0; i < n; i++) max_val = max(max_val, a[i]);
	queue<int> Q[10];
	int factor = 1;

	while (max_val != 0) {
		for (int i = 0; i < n; i++) Q[(a[i] / factor) % 10].push(a[i]);
		for (int i = 0, k = 0; i < 10; i++) {

			while (Q[i].empty() == false) {
				a[k++] = Q[i].front();
				Q[i].pop();
			}
		}
		max_val = max_val / factor;
		factor *= 10;
	}
	for (int i = 0; i < n; i++) cout << a[i] << " ";
}

//void radixSort_str(string a[], int n)
//{
//	int max_val = -1;
//	map<char, queue<string>> Q;
//
//	for (int i = 0; i < n; ++i) max_val = max(max_val, (int)a[i].size());
//	int factor = 1;
//	while (max_val--)
//	{
//		for (int i = 0; i < n; ++i)
//			if (((int)a[i].size() - factor) >= 0) Q[a[i][(int)a[i].size() - factor]].push(a[i]);
//			else Q[0].push(a[i]);
//
//		int k = 0;
//		for (auto e : Q)
//		{
//			while (Q[e.first].empty() == false)
//			{
//				a[k++] = Q[e.first].front();
//				Q[e.first].pop();
//			}
//		}
//		factor++;
//	}
//}
//
//int main() {
//	string a[] = { "vua", "code", "so", "cmm" };
//	int n = 4;
//	radixSort_str(a, n);
//	for (auto e : a) cout << e << " ";
//	return 0;
//}