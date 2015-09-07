#ifndef CAT_H_
#define CAT_H_

#include <iostream>

using namespace std;

class Cat {
private:
	bool happy;

public:
	void speak();
	Cat();
	~Cat();
};

// Constructor
Cat::Cat() {
	cout << "Cat created" << endl;
	happy = true;
}

// Destructor
Cat::~Cat() {
	cout << "Cat destroyed" << endl;
}

// Methods
void Cat::speak() {
	if (happy) {
		cout << "meow" << endl;
	} else {
		cout << "ssssssss..." << endl;
	}
}
#endif
