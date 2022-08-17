#include"fucntion.h"

int main() {
	string s;
	cout << "ENTER YOUR STRING : ";
	getline(cin, s);

	string c = conVert(s);
	if (s.size() == 0 || c.size() == 0 || c.size() == 1) cout << "IS PALINDROME !!!";
	else {
		if (checkPalindrome(c)) cout << "IS PALINDROME !!!";
		else cout << "IS NOT PALINDROME !!!";
	}
}