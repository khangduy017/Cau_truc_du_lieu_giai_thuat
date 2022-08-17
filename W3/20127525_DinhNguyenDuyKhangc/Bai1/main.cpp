#include"function.h"

int main(int argc, char** argv) {
	if (argc != 5) {
		cout << "Invalid !!!";
		return -1;
	}
	ifstream infile(argv[3]);
	ofstream outfile(argv[4]);
	int n;
	infile >> n;

	int a[100];
	for (int i = 0; i < n; i++)	infile >> a[i];

	int x = atoi(argv[2]);
	vector<int> index;
	switch (atoi(argv[1])) {
	case 1:
		index = linearSearch(a, n, x);
		break;
	case 2:
		index = sentinelSearch(a, n, x);
		break;
	case 3:
		QuickSort(a, 0, n - 1);
		index= binSearch(a,n,x);
		break;
	default:
		cout << "Invalid algorithm choice";
		return -1;
	}
	for (int i = 0; i < index.size(); i++)
		outfile << index[i] << " ";

	infile.close();
	outfile.close();
}