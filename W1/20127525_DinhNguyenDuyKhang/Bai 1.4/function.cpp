#include"function.h"

void fileout(const char* filename1, const char* filename2) {
	ifstream file1, file2;
	file1.open(filename1);
	file2.open(filename2);
	string s, s1, a, a1;
	while (true) {
		string x[100];
		string y[100];
		int i = 0, j = 0;
		if(file1.eof() == false) {
			getline(file1, s);
			stringstream sub1;
			sub1.clear();
			sub1 << s;
			while (sub1 >> s1) {
				x[i] = s1;
				i++;
			}
		}
		if (file2.eof() == false) {
			getline(file2, a);
			stringstream sub2;
			sub2.clear();
			sub2 << a;
			while (sub2 >> a1) {
				y[j] = a1;
				j++;
			}
		}

		if (i == j) {
			for (int k = 0; k < i; k++) {
				if (x[k] != y[k]) {
					cout << "< ";
					for (int h = 0; h < i; h++) {
						cout << x[h] << " ";
					}
					cout << endl << "> ";
					for (int h = 0; h < i; h++) {
						cout << y[h] << " ";
					}
					cout << endl;
					break;
				}
			}
		}
		if (i != j) {
			cout << "< ";
			for (int h = 0; h < i; h++) {
				cout << x[h] << " ";
			}
			cout << endl << "> ";
			for (int h = 0; h < j; h++) {
				cout << y[h] << " ";
			}
			cout << endl;
		}
		if (file1.eof() && file2.eof()) break;
	}

	file1.close();
	file2.close();
}