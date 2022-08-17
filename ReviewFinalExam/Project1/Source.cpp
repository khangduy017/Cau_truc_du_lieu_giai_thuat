// Nhập xuất dslk
// Thêm Node (đầu, cuối, vị trí bất kì)
// Xóa Node(đầu, cuối, vị trí bất kì)
// Sort tăng dần, giảm dần
// Nối 2 dslk
// In ngược dslk
// Xóa dslk
// Tìm Node
// Độ dài dslk


#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void Input(Node* &head, int n) {
	Node* p = head;
	int i = 0;
	while (i < n) {
		cin >> p->data;
		i++;
		if (i == n) p->next = nullptr;
		else {
			p->next= new Node;
			p = p->next;
		}
		
	}
}

void Output(Node* head) {
	Node* p = head;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
}

void addNodeHead(Node* &head, int value) {
	Node* p = new Node;
	p->data = value;
	p->next = head;
	head = p;
}

void addNodeMidle(Node*& head,int index, int value) {
	Node* p = new Node;
	Node* c = head;
	for (int i = 0; i < index - 1; i++) {
		c = c->next;
	}
	p->data = value;
	p->next = c->next;
	c->next=p;
}

void addNodeTail(Node*& head, int value) {
	Node* p = new Node;
	Node* c = head;
	while (c->next != nullptr) {
		c = c->next;
	}
	p->data = value;
	c->next = p;
	p->next = nullptr;
}

void deleteNode(Node*& head, int index) {
	if (index == 0) {
		head = head->next;
	}
	else {
		Node* c = head;
		for (int i = 0; i < index-1; i++) {
			c = c->next;
		}
		if (c->next->next == nullptr) c->next = nullptr;
		else	c->next = c->next->next;
	}
}


void sort(Node* &head) {
	Node* t = head;
	for (t; t->next != nullptr;t = t->next) {
		for (Node* c = t->next; c != nullptr; c = c->next) {
			if (t->data > c->data) {
				int temp = t->data;
				t->data = c->data;
				c->data = temp;
			}
		}
	}
}

void deleteValue(Node*& head, int value) {
	Node* c = head;
	Node* p = new Node;
	int i = 0;
	while (c != nullptr) {
		if (c->data == value) {
			deleteNode(head, i);
			p = head;
			for (int j = 0; j < i; j++) {
				p = p->next;
			}
			c = p;
		}
		else {
			c = c->next;
			i++;
		}
	}
}
void deletell(Node*& head) {
	Node* p = head;
	while (p != nullptr) {
		p = nullptr;
		p = p->next;
	}
}

void reverse(Node*& head) {
	Node* p = head;
	Node* d = NULL, * c = NULL;
	while (p != NULL) {
		c = p->next;
		p->next = d;
		d = p;
		p = c;
	}
	head = d;
}

void findNode(Node* head, int value) {
	Node* p = head;
	int i = 0, check = 1;
	while (p != nullptr) {
		if (p->data == value) {
			cout << value << " o node thu : "<<i;
			check = 0;
			break;
		}
		p = p->next;
		i++;
	}
	if (check == 1) cout << "Gia tri khong ton tai trong dslk";
}

void connectLinkedlist(Node* head1, Node* head2) {
	Node* total = new Node;
	Node* p = head1;
	Node* q = head2;
	Node* head = total;
	while (true) {
		if (p!=nullptr) {
			total->data = p->data;
			total->next = new Node;
			total = total->next;
			p = p->next;
		}
		else {
			total->data = q->data;
			total->next = new Node;
			
			q = q->next;
			if (q == nullptr) {
				total->next = nullptr;
				break;
			}
			else total = total->next;
		}
	}
	Output(head);
}
void SortedMerge(Node* a, Node* b) {
	if (a == NULL && b == NULL) cout << "Khong ton tai";
	else {
		Node* res = NULL;
		while (a != NULL && b != NULL) {
			if (a->data <= b->data) {
				Node* temp = a->next;
				a->next = res;
				res = a;
				a = temp;
			}
			else {
				Node* temp = b->next;
				b->next = res;
				res = b;
				b = temp;
			}
		}
		while (a != NULL)
		{
			Node* temp = a->next;
			a->next = res;
			res = a;
			a = temp;
		}
		while (b != NULL)
		{
			Node* temp = b->next;
			b->next = res;
			res = b;
			b = temp;
		}
	}
}

int main() {
	Node* p = new Node;
	int n;
	cout << "Nhap vao so luong node : ";
	cin >> n;
	Input(p, n);
	Node* q = new Node;
	int m;
	cout << "Nhap vao so luong node : ";
	cin >> m;
	Input(q, m);
	//cout << "add Node : \n";
	//addNodeHead(p, 5);
	//addNodeMidle(p, 2, 9);
	//addNodeTail(p, 7);
	Output(p);
	cout << endl;
	Output(q);
	cout << endl;
	cout << endl;

	//deleteNode(p, 4);
	//cout << "Delete : \n";
	//int k;
	//cout << "Gia tri can xoa : ";
	//cin >> k;
	//deleteValue(p, k);
	//sort(p);
	//deletell(p);
	//reverse(p);
	/*cout << "Nhap vao gia tri can tim : ";
	int k;
	cin >> k;
	findNode(p, k);*/
//	Output(p);
	conectLinkedlist(p, q);
}
