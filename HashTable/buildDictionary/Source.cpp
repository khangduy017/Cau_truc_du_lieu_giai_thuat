#include<iostream>
#include<string>
using namespace std;

class  HT{
public:
	struct Node	{
		string data;
		Node* next;
	};
	 HT();
	 void insertNode(string data);
	 void printNode();
	 string searchNode(string data);
	~ HT();

private:
	Node* head;
};

 HT:: HT(){
	 head = nullptr;
}
 
 void HT::insertNode(string data) {
	 Node* p = new Node;
	 p->next = nullptr;
	 p->data = data;
	 if (head == nullptr) {
		 head = p;
	 }
	 else {
		 Node* t = head;
		 while (t->next != nullptr) {
			 t = t->next;
		 }
		 t->next = p;
	 }
 }

 string HT::searchNode(string data) {
	 Node* p = head;
	 while (p != nullptr) {
		 if (strstr(p->data.c_str(),data.c_str()) >0) return p->data;
		 p = p->next;
	 }
	 return "";
 }

 void HT::printNode() {
	 Node* p = head;
	 while (p != nullptr) {
		 cout << p->data << " ";
		 p = p->next;
	 }
 }

 HT::~HT() {}


 int hashID(string s, int size) {
	 int sum = 0;
	 for (int i = 0; i < s.size(); i++) sum += int(s[i]);
	 return sum % size;
 }

 string search(HT a[], string s,int size) {
	 int id = hashID(s, size);
	 return a[id].searchNode(s);
	
 }

 void insert(HT a[], string key,string data, int size) {
	 int id = hashID(key, size);
	 if(search(a,key,size)=="") a[id].insertNode(key+": "+data);
 }

int main() {
	string name[] = { "direct","similar","solution","mouse","phone","mirror","book"};
	string mean[] = { "truc tiep","tuong tu","giai phap","chuot","dien thoai","guong","sach" };

	HT ht[10];
	for (int i = 0; i < 7; i++) insert(ht, name[i], mean[i], 7);

	string str;
	getline(cin, str);

	cout << search(ht, str, 7);

}