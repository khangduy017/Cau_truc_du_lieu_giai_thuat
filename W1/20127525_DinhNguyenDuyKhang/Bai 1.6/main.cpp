#include"function.h"

int main() {
	//khai bao
	int i = 0, j = 0,dem = 0;
	string a[100], b[100], s[100], s0[100], kq[100];
	
	infile(a, s, i, "f1.txt");
	infile(b, s0, j, "f2.txt");

	// check
	for (int f = 0; f < i; f++) {
		int checks = 0;
		for (int e = 0; e < j; e++) {
			if (s[f] == s0[e]) {
				Delete(b[e], s0[e]);
				a[f] += b[e];
				checks = 1;
			}
		}
		if (checks == 1) {
			kq[dem] += a[f];
			dem++;
		}
	}

	outfile("f3.txt", kq, dem);

}