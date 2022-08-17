#include"function.h"

int main() {
	ifstream filein;
	ofstream fileout;
	int a[100],aux[100];
	string b[100], bux[100];
	string id[100], iux[100];
	filein.open("employee.txt");
	fileout.open("sortedemponage.txt");
	int i = 0,j = 0;
	
	while (filein.eof() == false) {
		getline(filein, id[i], ',');
		getline(filein, b[i], ',');
		filein >> a[i];
		filein.ignore();
		i++;
	}


	QuickSort(b, a,id, 0, i - 1);
	mergesort(a,b,id, aux,bux,iux, 0, i-1);


	while (j < i) {
		fileout << id[j]<<","<<b[j]<<","<<a[j] << endl;
		j++;
	}

	
	filein.close();
	fileout.close();
}