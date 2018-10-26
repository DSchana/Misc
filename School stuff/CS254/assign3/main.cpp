#include "PStack.h"
#include "PStack.cpp"
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	PStack<int> s;

	s.enqueue(3, 4);
	s.enqueue(2, 2);
	s.enqueue(6, 1);
	s.enqueue(1, 1);
	s.enqueue(23);

	cout << s << endl << endl;
	cout << *s.dequeue() << endl << endl;
	cout << s << endl;

	return 0;
}
