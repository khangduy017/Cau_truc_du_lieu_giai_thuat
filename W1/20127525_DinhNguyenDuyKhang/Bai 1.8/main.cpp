#include"fucntion.h"


int main() {
	SinhVien sv;
	
	vector<SinhVien> v;
	Infile("Output.bin", v);

	for (auto c : v) {
		cout <<"Fullname : "<< c.name <<endl<< "Age : " << c.age <<endl<< "Address : " << c.address;
	}
}