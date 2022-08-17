#include<iostream>
#include<string>
using namespace std;

class LinkedList {
public:
	struct Node {
		string data;
		Node* next;
	};
	LinkedList();
	void insertNode(string data);
	void printLinkedList();
	bool searchNode(string data);

	~LinkedList();

private:
	Node* head;
};

LinkedList::LinkedList() {
	head = nullptr;
}

void LinkedList::insertNode(string data) {
	Node* p = new Node;
	if (head == nullptr) {
		p->data = data;
		p->next = nullptr;
		head = p;
	}
	else {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		p->data = data;
		p->next = nullptr;
		temp->next = p;
	}
}

void LinkedList::printLinkedList() {
	Node* p = head;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
}
bool LinkedList::searchNode(string data) {
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->data == data) return true;
		temp = temp->next;
	}
	return false;
}

LinkedList::~LinkedList() {}

int hashID(string str, int size) {
	int sumstr = 0;
	for (int i = 0; i < str.size(); i++) sumstr += int(str[i]);
	return sumstr % size;
}

void Insert(LinkedList hash[], string str, int size) {
	int id = hashID(str, size);
	hash[id].insertNode(str);
}

bool Search(LinkedList hash[], string str, int size) {
	int id = hashID(str, size);
	if (hash[id].searchNode(str)) return true;
	return false;
}


int main() {
	string str[]{ "C#","java","html","c++","nodeJS","reactNative","hash","table","javascipt","php","css" };
	LinkedList hash[12];
	for (string e : str) Insert(hash, e, 11);

	for (int i = 0; i < 11; i++) {
		cout << i << ": ";
		hash[i].printLinkedList();
		cout<<endl;
	}
	string str1;
	getline(cin,str1);
	if (Search(hash,str1, 11)) cout << "YES";
	else cout << "NO";
}