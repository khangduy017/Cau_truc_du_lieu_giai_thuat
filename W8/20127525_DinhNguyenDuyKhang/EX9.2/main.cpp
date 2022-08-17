#include"function.h"

int main() {
	
	int n = 0;
	string name[1000],numberP[1000],hash[1000][2],a, b, c;

	readFile("Monsters.txt", name, numberP, n);

	add(hash, name, numberP, n);

	printHash(hash, n);

	cout << "\nFIND\n";
	cout << "Enter name to find: ";
	getline(cin, a);
	find(hash, a, n);

	cout << "\nDELETE\n";
	cout << "Enter element to delete: ";
	getline(cin, b);
	Delete(hash, b, n);

	cout << "\nUPDATE\n";
	cout << "Enter element to updata: ";
	getline(cin, c);
	update(hash,c, n);

	printHash(hash, n);

}