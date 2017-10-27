#include "Stack.h"
#include <iostream>

using namespace std;

int main() {
	Stack<int> s;

	s.push(5);
	s.push(6);
	s.push(2);

	cout << s << endl;
}
