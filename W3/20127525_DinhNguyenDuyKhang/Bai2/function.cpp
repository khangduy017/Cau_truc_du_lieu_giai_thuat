#include"function.h"


void infile(const char* filename,string* key, string* value, int& n) {
	ifstream infile;
	infile.open(filename);
	while (infile.eof() == false) {
		getline(infile, key[n], ':');
		getline(infile, value[n]);
		n++;
	}
	infile.close();
}

int SearchStr(string* a, int n, string word) {
	for (int i = 0; i < n; i++) {
		if (a[i] == word) return i;
	}
	return -1;
}
