#include"function.h"

int main(int argc, char** argv) {
	string* key = new string[125000], * value = new string[125000];
	int n = 0,m = argc;

	infile("Input.txt", key, value, n);

	string* word = new string[m - 1];
	for (int i = 1; i < m - 1; i++) 	word[i] = argv[i];


	ofstream outfile(argv[m-1]);
	for (int i = 1; i < m - 1; i++) {
		int k = SearchStr(key, n, word[i]);
		if (k != -1) outfile << key[k] << ":" << value[k] << endl;
		else outfile << "' " << word[i] << " ' " << "is not found !!!\n";
	}
	delete[] key; delete[] value; delete[]word;
	outfile.close();
}