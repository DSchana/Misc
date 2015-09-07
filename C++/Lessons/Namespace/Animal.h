#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
using namespace std;

namespace animal {

class Cat {
public:
	Cat();
	virtual ~Cat();
	void speak();
};

Cat::Cat() {
	cout << "Animal cat created" << endl;
}

Cat::~Cat() {
	cout << "Animal cat destroyed" << endl;
}

void Cat::speak() {
	cout << "Sssssssssss" << endl;
}

}  // Namespace dsc

#endif
