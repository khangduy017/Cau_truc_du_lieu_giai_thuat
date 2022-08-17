#include"function.h"

int main() {
	ifstream filein;
	filein.open("Input.txt");
	int n;
	filein >> n;

	vector<vector<string>> v;
	while (!filein.fail()) {
		string s1, s3;
		getline(filein, s1);

		string s2 = " ";
		for (int i = 1; i < s1.size(); i++) {
			if (s1[i] == ')' || s1[i] == '(');
			else	s2 += s1[i];
		}
		stringstream sub;
		sub.clear();
		sub << s2;
		
		vector<string> f;
		while (sub >> s3) {
			f.push_back(s3);
		}
		v.push_back(f);
	}


	for (auto c : v) {
		for (auto f : c) {
			cout << f << " ";
		}
		cout << endl;
	}
	Node* root = new Node;
	root = nullptr;
	for (auto c : v) {
		for (auto f : c) {
			insertNode(root, f);
		}
	}

}