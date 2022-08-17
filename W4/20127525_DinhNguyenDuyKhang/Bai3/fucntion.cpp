#include"fucntion.h"

bool checkPalindrome(string s) {
	int l = s.size();
	stack<char> st;
	queue<char> q;

	int i = 0;
	for (; i < l / 2; i++) st.push(s[i]);
	if (l % 2 != 0) i++;
	for (; i < l; i++) q.push(s[i]);

	while (!st.empty()) {
		if (st.top() != q.front()) return false;
		st.pop();
		q.pop();
	}
	return true;
}

string conVert(string s) {
	string a;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') a += s[i];
		else if (s[i] >= 'A' && s[i] <= 'Z') a += s[i] + 32;
		else if (s[i] >= '0' && s[i] <= '9') a += s[i];
	}
	return a;
}