#include"fucntion.h"

void Infile(const char* filename, vector<SinhVien> &s) {
	fstream filein;
	SinhVien sv;
	filein.open(filename, ios::in, ios::binary);

	filein.read((char*)(&sv), sizeof(SinhVien));
	s.push_back(sv);
	filein.close();
}