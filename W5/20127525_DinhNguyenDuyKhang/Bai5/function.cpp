#include"function.h"

void addNode(Node*& head, char name[], int math, int physic, int chemis) {
	Node* p = new Node;
	p->Name = name;
	p->pointM = math;
	p->pointP = physic;
	p->pointC = chemis;
	p->next = nullptr;
	if (head == nullptr) {
		head = p;
	}
	else {
		Node* tmp = head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = p;
	}
}
void printLinkList(Node* head) {
	if (head == NULL) cout << "Empty !";
	else {
		cout << "List: \n";
		while (head != nullptr) {
			cout << head->Name << ": " << head->pointM << " " << head->pointP << " " << head->pointC << endl;
			head = head->next;
		}
	}
}

void searchStudentOnFN(Node* head, string fullName) {
	cout << "\nSearch name: " << fullName << "\nResult: \n";
	if (head == nullptr) cout << "No value !!!";
	else {
		Node* p = head;
		int check = 0;
		while (p != nullptr) {
			if (p->Name == fullName) {
				cout << p->Name << ": " << p->pointM << " " << p->pointP << " " << p->pointC << endl;
				check = 1;
			}
			p = p->next;
		}
		if (check == 0) cout << "NOT FOUND !!!";
	}
}

void calculateAverageScore(Node* head) {
	cout << "\nAverage Score: \n";
	if (head == nullptr) cout << "No value !!!";
	else {
		Node* p = head;
		while (p != nullptr) {
			float Aver = (float)(p->pointM + p->pointP + p->pointC) / 3;
			cout << p->Name << ": " << fixed << setprecision(2) << Aver << endl;
			p = p->next;
		}
	}
}

void deleteStudent(Node*& head, int index) {
	if (head == nullptr) cout << "No value !!!";
	else {
		Node* p = head;
		if (index == 0) {
			p = p->next;
			head = p;
		}
		else if (index == 1) {
			p->next = p->next->next;
		}
		else {
			int i = 0;
			for (int i = 0; i < index - 1; i++) {
				p = p->next;
				if (p->next->next == nullptr) {
					cout << "No value !!!\n";
					break;
				}
			}
			p->next = p->next->next;
		}
	}
}

void deleteSdWithSameName(Node*& head) {
	int i = 0;
	Node* p = head;
	while (p != nullptr) {
		Node* t = p->next;
		int j = i + 1;
		while (t != nullptr) {
			if (t->Name == p->Name) {
				deleteStudent(head, j);
				j--;
			}
			t = t->next;
			j++;
		}
		p = p->next;
		i++;
	}
}
void insertToEnd(Node*& head, char name[], int math, int physic, int chemis) {
	Node* p = new Node;
	p->Name = name;
	p->pointM = math;
	p->pointP = physic;
	p->pointC = chemis;
	p->next = nullptr;
	Node* tmp = head;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = p;
}

void insertToFirst(Node*& head, char name[], int math, int physic, int chemis) {
	Node* p = new Node;
	p->Name = name;
	p->pointM = math;
	p->pointP = physic;
	p->pointC = chemis;
	p->next = head;
	head = p;
}

void insertToAfterFirst(Node*& head, char name[], int math, int physic, int chemis) {
	Node* p = new Node;
	p->Name = name;
	p->pointM = math;
	p->pointP = physic;
	p->pointC = chemis;
	Node* c = head;
	p->next = c->next;
	c->next = p;
}

void insertToAfterName(Node*& head, char name[], int math, int physic, int chemis, string NamE) {
	Node* p = new Node;
	p->Name = name;
	p->pointM = math;
	p->pointP = physic;
	p->pointC = chemis;

	Node* c = head;
	while (c != nullptr) {
		if (c->Name == NamE) {
			p->next = c->next;
			c->next = p;
			break;
		}
		c = c->next;
	}
}

void topKStudentAverageScore(Node* head, int top) {
	float a[100];
	int i = 0;
	if (head == nullptr) cout << "No value !!!";
	else {
		Node* p = head;
		while (p != nullptr) {
			a[i] = (float)(p->pointM + p->pointP + p->pointC) / 3;
			p = p->next;
			i++;
		}
	}
	for (int j = 0; j < i - 1; j++) {
		for (int k = j + 1; k < i; k++) {
			if (a[j] < a[k]) swap(a[j], a[k]);
		}
	}

	for (int j = 0; j < i - 1; j++) {
		if (a[j + 1] == a[j]) {
			for (int k = j + 1; k < i - 1; k++) {
				a[k] = a[k + 1];
			}
			i--;
			j--;
		}
	}
	Node* t = head;
	int check = 0;
	if (top - 1 >= i) cout << "No Student !!!";
	else {
		cout << "\nTop " << top << " (Average >= " << a[top - 1] << ") : \n";
		while (t != nullptr) {
			if ((float)(t->pointM + t->pointP + t->pointC) / 3 >= a[top - 1]) {
				cout << t->Name << endl;
				check = 1;
			}
			t = t->next;
			i++;
		}
		if (check == 0) cout << "No Student !!!";
	}
}