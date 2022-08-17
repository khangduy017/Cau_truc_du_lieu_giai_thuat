#include"function.h"


void writefile(const char* filename, SinhVien sv) {
	fstream fileout;
	fileout.open(filename, ios::out, ios::binary);
	fileout.write((const char*)&(sv), sizeof(SinhVien));
	fileout.close();
}