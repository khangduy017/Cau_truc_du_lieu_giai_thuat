#include"function.h"

void infile(string a[], string s[100],int &i, const char*filename ) {
	ifstream filein1;
	filein1.open(filename);
	string s1, s2;
	while (filein1.eof() == false) {
		getline(filein1, s1);
		stringstream sub;
		sub.clear();
		sub << s1;
		while (sub >> s2) {
			a[i] = s2;
			i++;
		}
	}

	for (int k = 0; k < i; k++) {
		for (int h = 0; h < a[k].size(); h++) {
			s[k] += a[k][h];
			if (a[k][h + 1] == ':') break;
		}
	}

	filein1.close();
}

void outfile(const char* filename,string kq[100], int dem) {
	ofstream fileout;
	fileout.open(filename);
	for (int l = 0; l < dem; l++) {
		fileout << kq[l] << endl;
	}
	fileout.close();
}


void Delete(string& a, string& x) {
	int i = 0;
	for (; i < a.size() - x.size(); i++) {
		a[i] = a[i + 2];
	}
	for (; i < a.size(); i++) {
		a[i] = ' ';
	}
}