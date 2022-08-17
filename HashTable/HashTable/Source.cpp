#include<iostream>

using namespace std;

class LinkList{
public:
	struct Node {
		string data;
		Node* p_next;
	};
	LinkList();
	Node* creatNode(string data);
	void insertNode(string data);
	void printList();
	bool search(string data);
	void deallocate();
	~LinkList();
private:
	Node* head;
};

LinkList::LinkList()
{
	head = nullptr;
}

LinkList ::Node* LinkList::creatNode(string data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->p_next = nullptr;
	return newNode;
}

void LinkList::insertNode(string data){
	if (head == nullptr) head = creatNode(data);
	else {
		Node* parentNode = head;
		while (parentNode->p_next!=nullptr) {
			parentNode = parentNode->p_next;

		}
		parentNode->p_next = creatNode(data);
	}
}

void LinkList::printList() {
	Node* parentNode = head;
	while (parentNode) {
		cout << parentNode->data << " ";
		parentNode = parentNode->p_next;
	}
}

bool LinkList::search(string str) {
	Node* parentNode = head;
	while (parentNode) {
		if (parentNode->data == str) return true;	
		parentNode = parentNode->p_next;
	}
	return false;
}

void LinkList::deallocate() {
	Node* parenNode = head;
	Node* temp = nullptr;
	while (parenNode) {
		temp = parenNode;
		parenNode = parenNode->p_next;
		delete temp;

	}
	head = nullptr;
}

LinkList::~LinkList(){
}

int hash_function(string str, int hash_size) {
	int sum_ascii = 0;
	for (int i = 0; i < str.size(); i++) sum_ascii += int(str[i]);
	return sum_ascii % hash_size;
}

void insert_hash_table(LinkList hash_table[],string str, int hash_size) {
	int key = hash_function(str,hash_size);
	hash_table[key].insertNode(str);
}

bool search(LinkList hash_table[], string str, int hash_size) {
	int key = hash_function(str,hash_size);
	if (hash_table[key].search(str) == true) return true;
	return false;
}

int main() {
	string str[7]{ "dinh","nguyen","duy","khang","k","n" };
	LinkList hashtable[7];
	for (string e : str) 	insert_hash_table(hashtable, e, 6);
	for (int i = 0; i < 5; i++) {
		cout << i << ": ";
		hashtable[i].printList();
		cout << endl;
	}
	if (search(hashtable, "dinh", 6)) cout << "Present !!!";
	else cout << "Not Present !!!"; 
}