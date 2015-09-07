#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
using namespace std;

class Person {
private:
	string name;
	string age;

public:
	Person();
	string toString();
	string getName();
	void setName(string newName);
};

Person::Person() {
	name = "John";
	age = "34";
}

string Person::toString() {
	return name + " " + age;
}

void Person::setName(string newName) {
	name = newName;
	cout << "new name set" << endl;
}

string Person::getName() {
	return name;
}

#endif
