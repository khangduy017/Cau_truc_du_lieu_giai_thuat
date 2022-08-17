#include"function.h"

using namespace std;
int n = 0;

int main() {
	
	char* a = new char[n];
	//push
	push(a,n, 'a');
	push(a,n, 'b');
	push(a,n, 'c');
	push(a,n, 'd');

	int k = n;
	cout << "STACK AFTER PUSH CHAR : \n";
	for (int i = 0; i < k; i++) {
		cout << top(a) << endl;	
		pop(a, n);
	}
	
	//push
	push(a, n, 'a');
	push(a, n, 'b');
	push(a, n, 'c');
	push(a, n, 'd');
	push(a,n, 'e');
	
	cout << "SIZE OF STACK AFTER PUSH 5 ELEMENT: " << size(a, n) << "\n";

	if (empty(a, n)) cout << "Empty !!!"<<endl;
	else cout << "Not Empty !!!"<<endl;
	
	//if (full(a,n)) cout << "STACK IS FULL !!!";
}