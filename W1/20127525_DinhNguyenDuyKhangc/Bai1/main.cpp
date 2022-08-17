#include"function.h"

using namespace std;

int main() {
	ofstream fileout;
	fileout.open("Output.txt");
	fileout << "Hello, World";
	fileout.close();
}