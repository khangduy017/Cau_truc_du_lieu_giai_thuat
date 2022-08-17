#include"function.h"

int main() {
	Node* head = new Node;
	head = nullptr;
	cout << "Check file...\n";
	checkFile(head, "student.data");
	
	cout << "\n============================MENU=========================\n";
	cout << "1/ Insert student \n";
	cout << "2/ Find a student updating of the student info if found \n";
	cout << "3/ Dislay list all students \n";
	cout << "4/ Dislay list of all graduated students \n";
	cout << "5/ Delete an student given by its code \n";
	cout << "6/ Save all students in file student.data \n";
	cout << "0/ Exit\n";


	while (true) {
		int choose;
		cout << "\nEnter your choose: ";
		cin >> choose;

		if (choose == 1) {
			string id, name, birth;
			bool graduate;
			cout << "Enter id: ";
			cin >> id;
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter birthday: ";
			cin.ignore();
			cin >> birth;
			cout << "Graduate: ";
			cin >> graduate;
			insertNode(head, id, name, birth, graduate);
		}
		else if (choose == 2) {
			string id;
			cout << "\nEnter id to find: ";
			cin >> id;
			searchNode(head, id);
		}
		else if (choose == 3) {
			cout << "\nDislay list all student: \n\n";
			dislayList(head);
		}
		else if (choose == 4) {
			cout << "\nDislay list graduate student: \n";
			dislayGraduate(head);
		}
		else if (choose == 5) {
			string id;
			cout << "\nEnter id to delete: ";
			cin >> id;
			Delete(head, id);
			cout << "Delete...\nDelete success !!!\n";
		}
		else if (choose == 6) {
			cout << "\nSave file...\n";
			saveFile(head, "student.data");
			cout << "Complete !!!\n";
		}
		else if (choose == 0) {
			break;
		}
		else
			cout << "\nNo choose in menu ! Please enter again \n";
	}
}