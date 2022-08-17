#include <iostream>
#include <map>
#include <queue>
using namespace std;

void radixSort_str(string a[], int n)
{
	int max_val = -1;
	map<char, queue<string>> Q;

	for (int i = 0; i < n; ++i) max_val = max(max_val, (int)a[i].size());
	int factor = 1;
	while (max_val--)
	{
		for (int i = 0; i < n; ++i)
			if (((int)a[i].size() - factor) >= 0) Q[a[i][(int)a[i].size() - factor]].push(a[i]);
			else Q[0].push(a[i]);

		int k = 0;
		for (auto e : Q)
		{
			while (Q[e.first].empty() == false)
			{
				a[k++] = Q[e.first].front();
				Q[e.first].pop();
			}
		}
		factor++;
	}
}

int main()
{
	string a[] = { "vua", "code", "so", "cmm" };
	int n = 4;
	radixSort_str(a, n);
	for (auto e : a) cout << e << " ";
	return 0;
}