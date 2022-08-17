#include"function.h"

void finfichero(int n, const char* filename) {
	int i = -1;
	ifstream filein;
	filein.open(filename);
	string s,s1;
	queue<vector<string>> v;
	while (filein.eof() == false) {
		getline(filein, s);
		stringstream sub;
		sub.clear();
		sub << s;
		vector<string> v1;
				
		while (sub >> s1) {
			v1.push_back(s1);
		}
		v.push(v1);
		i++;
	}
	
	for (int j = 0; j < i - n; j++)	v.pop();

	while (!v.empty()) {
		auto c = v.front();
		for (auto d : c) cout << d << " ";
		v.pop();
		cout << endl;
	}


}