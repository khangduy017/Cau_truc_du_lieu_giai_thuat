#include"function.h"
int n = 0;

int main() {
	int* c = new int[n];
	push(c,n, 3);
	push(c,n, 4);
	push(c,n, 5);
	push(c,n, 6);


	int k = n;
	cout << "QUEUE AFTER PUSH : \n";
	for (int i = 0; i < k; i++) {
		cout << value(c,n) << endl;
		pop(c,n);
	}
	//if (empty(c, n)) cout << "Empty !!!"<<endl;
	push(c, n, 3);
	push(c, n, 4);
	push(c, n, 5);
	push(c, n, 6);
	cout << "SIZE OF QUEUE AFTER PUSH 4 ELEMENT : " << size(c, n) << endl;

	if (full(c,n)) cout << "Full !!";
	if (empty(c, n)) cout << "Empty !!!"<<endl;
	else cout << "No Empty !!!"<<endl;
}