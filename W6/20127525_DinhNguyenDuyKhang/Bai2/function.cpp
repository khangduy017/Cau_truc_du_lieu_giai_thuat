#include"function.h"

void insertNode(Node*&root,string id,string name,string birth,bool graduate) {
	if (root == nullptr) {
		Node* p = new Node;
		p->id = id;
		p->name = name;
		p->birth = birth;
		p->graduate = graduate;
		p->left = nullptr;
		p->right = nullptr;
		//x++;
		root = p;
	}
	else {
		if (_stricmp(id.c_str(), (root->id).c_str()) < 0) {
			insertNode(root->left, id, name, birth, graduate);
		}
		else insertNode(root->right, id, name, birth, graduate);
	}
}

void updateNode(Node*&root, string id, string name, string birth, bool graduate) {
	root->id = id;
	root->name = name;
	root->birth = birth;
	root->graduate = graduate;
}

void searchNode(Node* root, string id) {
	if (root == nullptr) cout << "Not found !!!";
	else if (root->id == id) {
		cout << "Find success !!!\n";
		string id, name, birth;
		bool graduate;
		cout << "Enter new id: ";
		cin >> id;
		cout << "Enter new name: ";
		cin >> name;
		cout << "Enter new birthday: ";
		cin.ignore();
		cin >> birth;
		cout << "Graduate: ";
		cin >> graduate;
		updateNode(root, id, name, birth, graduate);
	}
	else if (_stricmp(id.c_str(), (root->id).c_str()) < 0) {
		searchNode(root->left, id);
	}
	else searchNode(root->right, id);
}
int index = 0;
void preOrderNode(Node* root,string id[],string name[],string birth[],bool graduate[]) {
	if (root != nullptr) {
		id[index] = root->id;
		name[index] = root->name;
		birth[index] = root->birth;
		graduate[index] = root->graduate;
		index++;
		preOrderNode(root->left, id, name, birth, graduate);
		preOrderNode(root->right,id, name, birth, graduate);
	}
}

void dislayList(Node* root) {
	string id[1000];
	string name[1000];
	string birth[1000];
	bool graduate[1000];
	preOrderNode(root, id, name, birth, graduate);

	for (int i = 0; i < index-1; i++) {
		for (int j = i + 1; j < index; j++) {
			if (name[i][0] > name[j][0]) {
				swap(name[i], name[j]);
				swap(id[i], id[j]);
				swap(birth[i], birth[j]);
				swap(graduate[i], graduate[j]);
			}
		}
	}

	for (int i = 0; i < index; i++) {
		cout <<i+1 <<"/ ID: " << id[i] << endl;
		cout << "   Name: " << name[i] << endl;
		cout << "   Birth day: " << birth[i]<<endl;
		if (graduate[i]) cout << "   Graduate: " << 1<<endl;
		else cout << "   Graduate: " << 0<<endl;
		cout << endl;
	}
	index = 0;
}

void dislayGraduate(Node* root) {
	string id[1000];
	string name[1000];
	string birth[1000];
	bool graduate[1000];
	preOrderNode(root, id, name, birth, graduate);

	for (int i = 0; i < index - 1; i++) {
		for (int j = i + 1; j < index; j++) {
			if (name[i][0] > name[j][0]) {
				swap(name[i], name[j]);
				swap(id[i], id[j]);
				swap(birth[i], birth[j]);
				swap(graduate[i], graduate[j]);
			}
		}
	}

	for (int i = 0; i < index; i++) {
		if (graduate[i]) {
			cout<<i+1 << "/ ID: " << id[i]<<endl;
			cout << "   Name: " << name[i] << endl;
			cout << "   Birth day: " << birth[i] << endl;
			cout << endl;

		}
	}
	index = 0;
}

Node* deleteNode(Node* root, string id){
	if (root == nullptr) return root;

	if (_stricmp(id.c_str(), (root->id).c_str()) < 0) {
		root->left = deleteNode(root->left, id);
		return root;
	}
	else if (_stricmp(id.c_str(), (root->id).c_str()) > 0) {
		root->right = deleteNode(root->right, id);
		return root;
	}

	if (root->left == nullptr) {
		Node* temp = root->right;
		delete root;
		return temp;
	}
	else if (root->right == nullptr) {
		Node* temp = root->left;
		delete root;
		return temp;
	}

	else {
		Node* succParent = root;
		Node* succ = root->right;
		while (succ->left != NULL) {
			succParent = succ;
			succ = succ->left;
		}

		if (succParent != root)
			succParent->left = succ->right;
		else
			succParent->right = succ->right;
		root->id = succ->id;
		delete succ;
		return root;
	}
}

void Delete(Node* root, string id) {
	deleteNode(root, id);
}

void saveFile(Node* root, const char* filename) {
	ofstream fileout;
	fileout.open(filename);


	string id[1000];
	string name[1000];
	string birth[1000];
	bool graduate[1000];
	preOrderNode(root, id, name, birth, graduate);

	int n=0;
	while (id[n].size() >0) n++;
	fileout << n<<endl;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (name[i][0] > name[j][0]) {
				swap(name[i], name[j]);
				swap(id[i], id[j]);
				swap(birth[i], birth[j]);
				swap(graduate[i], graduate[j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		fileout<< id[i] << endl;
		fileout<< name[i] << endl;
		fileout<< birth[i] << endl;
		if (graduate[i]) fileout<< 1 << endl;
		else fileout << 0 << endl;
	}
	index = 0;
	fileout.close();
}

void checkFile(Node*& head, const char* filename) {
	ifstream filein;
	filein.open("student.data");
	int n;
	filein >> n;
	if (n>0) {
		cout << "Have data in file !\n";
		int i = 0;
		while (i < n) {
			string id, name, birth;
			bool graduate;
			filein >> id;
			filein >> name;
			filein >> birth;
			filein >> graduate;
			insertNode(head, id, name, birth, graduate);
			i++;
		}
	}
	else cout << "File is empty !\n";
	filein.close();
}