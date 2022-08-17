#include"function.h"


void add(tagNODE*& root, SINHVIEN sv) {
	tagNODE* p = new tagNODE;
	p->SV = sv;
	p->pNext = nullptr;

	if (root == nullptr) {
		root = p;
	}
	else {
		tagNODE* t = root;
		while (t->pNext != nullptr)	t = t->pNext;
		t->pNext = p;
	}
}

void printDTB(tagNODE* root) {
	cout << "Nhung sinh vien co DTB<5: \n";
	int check = 0;
	while (root != nullptr) {
		if (root->SV.DTB < 5) {
			check = 1;
			cout << "MSSV:" << root->SV.MSSV<<endl;
			cout << "Ten: " << root->SV.TenSV<<endl;
			cout<< "DTB: " << root->SV.DTB << endl<<endl;
		}
		root = root->pNext;
	}
	if (check == 0) cout << "Khong co DTB<5! \n";
}

tagNODE* deleteNodeValue(tagNODE* root, int value) {
	if (root->SV.MSSV == value) {
		root = root->pNext;
	}
	else {
		tagNODE* p = root;
		while (p->pNext != NULL && p->pNext->SV.MSSV != value) {
			p = p->pNext;
		}
		if (p->pNext == NULL) cout << "No value !!!\n";
		else {
			if (p->pNext->pNext == NULL) p->pNext = NULL;
			else p->pNext = p->pNext->pNext;
		}
	}
	return root;
}
void deleteNode(tagNODE*& root, int value) {
	root = deleteNodeValue(root, value);
}

void printSV(tagNODE* root, int mssv){
	if (root == nullptr) return;
	if (root->SV.MSSV == mssv) return;
	printSV(root->pNext,mssv);
	cout << "MSSV:" << root->SV.MSSV << endl;
	cout << "Ten: " << root->SV.TenSV << endl;
	cout << "DTB: " << root->SV.DTB << endl << endl;
}

tagNODE *deleteLinkList(tagNODE* head) {
	tagNODE* p = new tagNODE;
	tagNODE*next = NULL;
	while (p != NULL) {
		next = p->pNext;
		free(p);
		p = next;
	}
	p->pNext ==nullptr;
	head = nullptr;
	return head;
}

void deleteLL(tagNODE*&root) {
	root = deleteLinkList(root);
}