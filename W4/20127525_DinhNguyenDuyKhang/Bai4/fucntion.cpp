#include"fucntion.h"

double postFix(istream& s) {
	stack<double> val;
	string tok;

	while (!s.eof()) {
		s >> tok;
		if (tok == " ");
		else if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
			double a = val.top(); val.pop();
			double b = val.top(); val.pop();
			if (tok == "+") val.push(a + b);
			else if (tok == "-") val.push(b - a);
			else if (tok == "*") val.push(b * a);
			else	val.push(b / a);
		}
		else val.push(stod(tok));
	}
	return val.top();
}