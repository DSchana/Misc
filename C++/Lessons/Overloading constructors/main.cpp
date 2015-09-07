// main.cpp

#include <iostream>
#include "Person.h"

using namespace std;

int main() {
	Person person1;
	Person person2("Bob");
	Person person3("Kim", 17);

	cout << person1.toString() << endl;
	cout << person2.toString() << endl;
	cout << person3.toString() << endl;

	return 0;
}
