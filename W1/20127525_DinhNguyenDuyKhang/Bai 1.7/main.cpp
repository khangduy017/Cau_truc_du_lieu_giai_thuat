#include"function.h"

int main() {
	SinhVien sv;
	cout << "Enter fullname : ";
	gets_s(sv.name);
	cout << "Enter age : ";
	cin >> sv.age;
	cin.ignore();
	cout << "Enter address : ";
	gets_s(sv.address);


	writefile("Output.bin", sv);
}
