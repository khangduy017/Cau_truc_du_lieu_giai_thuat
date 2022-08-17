#include"function.h"

int main() {
	int n, x;
	cout << "Enter number of array: ";
	cin >> n;
	int a[1000];
	cout << "Enter elements: \n";
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << "\n=========================MENU=========================\n";
	cout << "1/ Chaining Method\n";
	cout << "2/ Linear Probing\n";
	cout << "3/ Quadratic Probing\n";
	cout << "4/ Double hashing\n";
	cout << "0/ Exit\n";
	while(true){
		int choose, x;
		cout << "\nEnter your choose: ";
		cin >> choose;
		vector<int> hash[1000];
		int Hash[1000] = {0};
		int check = 0;
		switch (choose){
		case 1:
			for (int i = 0; i < n; i++) Insert1(hash, a[i], n);
			cout << "Enter x: ";
			cin >> x;
			if (Search1(hash, x, n)) cout << "Present !\n";
			else cout << "Not present !\n";
			break;
		case 2:
			for (int i = 0; i < n; i++) Insert2(Hash, a[i], n,0);
			cout << "Enter x: ";
			cin >> x;
			if (Search2(Hash, x, n)) cout << "Present !\n";
			else cout << "Not present !\n";
			break;
		case 3:
			for (int i = 0; i < n; i++) Insert3(Hash, a[i], n, 0);
			cout << "Enter x: ";
			cin >> x;
			if (Search3(Hash, x, n)) cout << "Present !\n";
			else cout << "Not present !\n";
			break;
		case 4:
			for (int i = 0; i < n; i++) Insert4(Hash, a[i], n, 0);
			cout << "Enter x: ";
			cin >> x;
			if (Search4(Hash, x, n)) cout << "Present !\n";
			else cout << "Not present !\n";
			break;
		case 0:
			check = 1;
			break;
		default:
			cout << "No choose ! Enter again !\n";
			break;
		}
		if (check == 1) break;
	}

}