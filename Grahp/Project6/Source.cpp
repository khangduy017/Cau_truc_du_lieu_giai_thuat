#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void DFS(int a[][100], int n, bool visit[], int start) {
	visit[start] = true;
	cout << start << " ";

	for (int i = 1; i <= n; ++i) {
		if (a[start][i] == 1) {
			if (visit[i] == true)	continue;
			DFS(a, n, visit, i);
		}
	}
}

int main() {
	int a[100][100], n, m;
	ifstream inp("input.txt");
	
	inp >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) a[i][j] = 0;
	}

	for (int u, v, i = 0; i < m; ++i) {
		inp >> u >> v;
		a[u][v] = 1;
	}

	inp.close();

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) cout<< a[i][j]<<" ";
		cout << endl;
	}
	cout << endl;	

	bool visit[100];
	DFS(a, n, visit, 2);
}
