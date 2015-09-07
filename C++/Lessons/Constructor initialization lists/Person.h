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
	Person(string name, int age);
	string toString();
};

// Methods
Person::Person(): name("unnamed"), age(0) {

}

Person::Person(string name, int age): name(name), age(age) {

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
