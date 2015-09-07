#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <sstream>

using namespace std;

class Person {
private:
	string name;
	int age;

public:
	Person();
	Person(string newName) {name = newName; age = 0;};  // in line constructor
	Person(string newName, int newAge);
	string toString();
};

// Methods
Person::Person() {
	name = "undefined";
	age = 0;
}

Person::Person(string newName, int newAge) {
	name = newName;
	age = newAge;
}

string Person::toString() {
	stringstream ss;
	
	ss << "Name: ";
	ss << name;
	ss << "; Age: ";
	ss << age;

	return ss.str();
}

#endif
