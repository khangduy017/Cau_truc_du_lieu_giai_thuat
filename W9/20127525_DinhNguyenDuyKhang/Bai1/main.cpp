#include"function.h"


int main() {
	tagNODE* root = nullptr;
	for (int i = 0; i < 10; i++) {
		tagSINHVIEN sv;
		cout << "SV" << i + 1 << endl;
		cout << "Nhap mssv : ";
		cin >> sv.MSSV;
		cout << "Nhap ten sinh vien: ";
		cin >> sv.TenSV;
		cout << "Nhap diem trung binh: ";
		cin >> sv.DTB;

		add(root, sv);
	}

	printDTB(root);

	int mssv;
	cout << "\nNhap mssv can xoa: ";
	cin >> mssv;
	deleteNode(root, mssv);
	
	int k;
	cout << "Nhap MSSV can in tu do: ";
	cin >> k;
	printSV(root, k);
	
	// giai phong Linklist
	deleteLL(root);
}