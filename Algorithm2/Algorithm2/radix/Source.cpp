#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <map>
using namespace std;
void sieve(int N) {
	int i;
	int *a = new int[N];
	for (i = 2; i < N; i++) a[i] = 1;
	for (i = 2; i < N; i++)
		if (a[i])
			for (int j = i; i*j < N; j++) a[i*j] = 0;
	for (i = 2; i < N; i++)
		if (a[i]) cout << " " << i;
	delete[] a;
}
template <class Item >
int partition(Item a[], int l, int r) {
	int i = l - 1, j = r; Item v = a[r];
	for (;;) {
		while (a[++i] < v);
		while (v < a[--j]) if (j == l) break;
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	swap(a[i], a[r]);
	return i;
}
template <class Item >
void quicksort(Item a[], int l, int r) {
	stack<int> st;
	st.push(l);
	st.push(r);
	while (!st.empty()) {				
		int i = partition(a, l, r);
		// call quicksort(a, l, i - 1);
		if (l < i - 1) {
			st.push(l);
			st.push(i - 1);
		}
		// call quicksort(a, i + 1, r);
		if (i + 1 < r) {
			st.push(i + 1);
			st.push(r);
		}		
		// end function
		r = st.top(); st.pop();
		l = st.top(); st.pop();
	}
}
void HanoiTower(int n, int a, int b, int c) {
	if (n > 0) {
		HanoiTower(n - 1, a, c, b);
		cout << "move disc from " << (char)a << " to " << (char)c << endl;
		HanoiTower(n - 1, b, a, c);
	}
}
struct tang {
	int n;
	char a;
	char b;
	char c;
};
void HNTower(int n, char a, char b, char c) {
	stack<tang> st;
	tang set;
	int N;
	set.a = a, set.b = b, set.c = c;
	set.n = n;
	st.push(set);
	do {
		set = st.top();
		st.pop();
		a = set.a; b = set.b; c = set.c;
		if (set.n == 1) {
			cout << "Move " << set.a << " to " << set.c << "\n";
		}
		else {
			N = set.n;
			set.n = N - 1; set.a = b; set.b = a; set.c = c;
			st.push(set);
			set.n = 1; set.a = a; set.b = ' '; set.c = c;
			st.push(set);
			set.n = N - 1; set.a = a; set.b = c; set.c = b;
			st.push(set);
		}
	} while (!st.empty());
}
double evaluate2(istream& in) {
	stack <string > ops;
	stack <double > vals;
	string tok;
	while (!in.eof()) {
		in >> tok;
		if (tok == "(");
		else if (tok == "+" || tok == "*") ops.push(tok);
		else if (tok == ")") {
			string op = ops.top(); ops.pop();
			double val2 = vals.top(); vals.pop();
			double val1 = vals.top(); vals.pop();
			if (op == "+") vals.push(val1 + val2);
			else if (op == "*") vals.push(val1 * val2);
		}
		else vals.push(stod(tok));
	}
	return vals.top();
}
short precedence(char a) {
	if (a == '*' || a == '/')
		return 2;
	else if (a == '+' || a == '-')
		return 1;
	else
		return 0;
}
double cal(double a, double b, char opr) {
	if (opr == '*')
		return a * b;
	else if (opr == '/' && a != 0)
		return b / a;
	else if (opr == '+')
		return a + b;
	else if (opr == '-')
		return b - a;
}
int evaluate(string s) {
	int i;
	stack <int> values;
	stack <char> ops;

	s += ' )';
	ops.push('(');
	for (i = 0; i < s.length(); i++) {
		if (s[i] == ' ')
			continue;
		else if (s[i] == '(') {
			ops.push(s[i]);
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			int val = 0;
			while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
				val = (val * 10) + (s[i] - '0');
				i++;
			}
			values.push(val);
			i--;
		}
		else if (s[i] == ')') {
			while (!ops.empty() && ops.top() != '(') {
				int val2 = values.top();
				values.pop();

				int val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(cal(val2, val1, op));
			}
			if (!ops.empty())
				ops.pop();
		}
		else {
			while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
				int val2 = values.top();
				values.pop();

				int val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(cal(val2, val1, op));
			}
			ops.push(s[i]);
		}
	}
	/*while (!ops.empty()) {
		int val2 = values.top();
		values.pop();

		int val1 = values.top();
		values.pop();

		char op = ops.top();
		ops.pop();

		values.push(cal(val2, val1, op));
	}*/
	return values.top();
}
int main() {
	string s = "( 4 +  5 ) * 20";
	cout << s << " = " << evaluate(s);
}