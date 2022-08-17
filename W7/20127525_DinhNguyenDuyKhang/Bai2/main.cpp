#include"function.h"

int main() {
	ifstream filein;
	ofstream fileout;
	filein.open("Input.txt");
	fileout.open("Output.txt");

	int n;
	filein >> n;
	filein.ignore();

	while (!filein.eof()) {
		Node* root;
		root = nullptr;
		
		string s, s1;
		getline(filein, s);
		
		stringstream sub;
		sub << s;
		
		int a;
		while (sub >> s1) {
			a = stoi(s1);
			insertNode(root, a);
		}
		fileout << checkAVL(root) << "\n";
	}
}