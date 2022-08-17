#include"fucntion.h"

int main() {
	string s;
	cout << "Enter expression : ";
	getline(cin,s);
	stringstream ss(s);
	cout <<"Result : \n"<< s << " = "<<fixed<<setprecision(2) << postFix(ss);
}

