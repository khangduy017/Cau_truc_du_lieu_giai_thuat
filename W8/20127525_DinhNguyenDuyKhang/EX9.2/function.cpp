#include"function.h"

void readFile(const char* filename, string name[], string num[], int& n) {
	ifstream filein;
	filein.open(filename);

	string s[1000];
	while (!filein.eof()) {
		getline(filein, s[n]);
		n++;
	}
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (s[i][j + 1] < '0' || s[i][j + 1]>'9') {
			name[i] += s[i][j];
			j++;
		}
		j++;
		while (j < s[i].size()) {
			num[i] += s[i][j];
			j++;
		}
	}
}

void printHash(string hash[][2], int n) {
	cout << "LIST:\n";
	for (int i = 0; i < n; i++) {
		cout << hash[i][0] << " " << hash[i][1] << endl;
	}
}

int hashCode(string s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) sum += (int)s[i];
	return sum;
}

int h(string s, int size, int i) {
	int sum = hashCode(s);
	return (sum + i) % size;
}

void add(string hash[][2], string name[], string num[], int &size) {
	for (int i = 0; i < size; i++) {
		int id = h(name[i], size, 0);
		int j = 1;
		while (hash[id][0].size() > 0) {
			id = h(name[i], size, j);
			j++;
		}
		hash[id][0] = name[i];
		hash[id][1] = num[i];
	}
}

void find(string hash[][2], string name, int size) {
	int j = 0;
	int check = 0;
	while (j < size) {
		int id = h(name, size, j);
		if (name == hash[id][0]) {
			cout <<"Number phone: "<< hash[id][1]<<endl;
			check = 1;
			break;
		}
		j++;
	}
	if (check == 0) cout << "Not present !\n";
}

void Delete(string hash[][2], string name, int &size) {
	int j = 0;
	int check = 0;
	while (j < size) {
		int id = h(name, size, j);
		if (name == hash[id][0]) {
			for (int i = id; i < size - 1; i++) {
				hash[i][0] = hash[i+1][0];
				hash[i][1] = hash[i+1][1];
			}
			size--;
			check = 1;
			break;
		}
		j++;
	}
	if (check == 0) cout << "Not present !\n";
}

void update(string hash[][2], string name, int size) {
	int j = 0;
	int check = 0;
	while (j < size) {
		int id = h(name, size, j);
		if (name == hash[id][0]) {
			string s, x;
			cout << "Enter new name: ";
			getline(cin, s);
			cout << "Enter new number phone: ";
			cin >> x;
			hash[id][0] = s;
			hash[id][1] = x;
			cout << endl;
			check = 1;
			break;
		}
		j++;
	}
	if (check == 0) cout << "Not present !\n";
}