#include"function.h"

int main() {
	SinhVien sv;

	fstream filein;
	filein.open("Input.bin", ios::in | ios::binary);
	filein.seekg(0, ios::end);
	int pos = filein.tellg();
	int n = pos / sizeof(SinhVien);
	filein.seekg(0, ios::beg);

	vector<SinhVien> f;
	for (int i = 0; i < n; i++) {
		filein.read((char*)(&sv), sizeof(SinhVien));
		f.push_back(sv);
	}

	Node* head = new Node;
	head = nullptr;
	for (auto c : f) {
		addNode(head, c.name, c.pointM, c.pointP, c.pointC);
	}

	cout << "-----------------MENU--------------------" << endl;
	cout << "1/  Display list on console screen\n";
	cout << "2/  Search students based on full name\n";
	cout << "3/  Calculate average score of each student\n";
	cout << "4/  Delete a student from list based on index\n";
	cout << "5/  Delete students with same name, retain only\n"; 
	cout<<  "    first student with this name\n";
	cout << "6/  Insert a new student at the end of list\n";
	cout << "7/  Insert a new student before first element\n";
	cout << "8/  Insert a new student after first element\n";
	cout << "9/  Insert a new student after specific name\n";
	cout << "10/ Search top k students based on average score \n";
	cout << "0/  Exit\n";

	while (true) {
		int choose;
		string name;
		int index;
		int check = 0;
		char nameA[50];
		int diemT;
		int diemL;
		int diemH;

		cout << "\n\nEnter your choose : ";
		cin >> choose;
		switch (choose) {
		case 1:
			printLinkList(head);
			break;
		case 2:
			cin.ignore();
			cout << "Enter fullname: ";
			getline(cin, name);
			searchStudentOnFN(head, name);
			break;
		case 3:
			calculateAverageScore(head);
			break;
		case 4:
			cout << "Enter index: ";
			cin >> index;
			deleteStudent(head, index);
			break;
		case 5:
			cout << "Complete !!!\n";
			deleteSdWithSameName(head);
			break;
		case 6:
			cin.ignore();
			cout << "Enter name: ";
			cin.getline(nameA, 50);
			cout << "Enter math score: ";
			cin >> diemT;
			cout << "Enter physics score: ";
			cin >> diemL;
			cout << "Enter chemistry score: ";
			cin >> diemH;
			insertToEnd(head, nameA, diemT, diemL, diemH);
			break;
		case 7:
			cin.ignore();
			cout << "Enter name: ";
			cin.getline(nameA, 50);
			cout << "Enter math score:";
			cin >> diemT;
			cout << "Enter physics score: ";
			cin >> diemL;
			cout << "Enter chemistry score: ";
			cin >> diemH;
			insertToFirst(head, nameA, diemT, diemL, diemH);
			break;
		case 8:
			cin.ignore();
			cout << "Enter name:";
			cin.getline(nameA, 50);
			cout << "Enter math score: ";
			cin >> diemT;
			cout << "Enter physics score: ";
			cin >> diemL;
			cout << "Enter chemistry score: ";
			cin >> diemH;
			insertToAfterFirst(head, nameA, diemT, diemL, diemH);
			break;
		case 9:
			cin.ignore();
			cout << "Enter name need insert after: ";
			getline(cin, name);
			cout << "Enter name: ";
			cin.getline(nameA, 50);
			cout << "Enter math score: ";
			cin >> diemT;
			cout << "Enter physics score: ";
			cin >> diemL;
			cout << "Enter chemistry score: ";
			cin >> diemH;
			insertToAfterName(head, nameA, diemT, diemL, diemH, name);
			break;
		case 10:
			cout << "Enter top:";
			int k;
			cin >> k;
			topKStudentAverageScore(head, k);
			break;
		case 0:
			check = 1;
			cout << "Goodbye !!!";
			break;
		default:
			cout << "No choose !!! Please enter choose again \n";
			break;
		}

		if (check == 1) break;

	}
}
