#ifndef CAT_H_
#define CAT_H_

#include <iostream>
using namespace std;

namespace cats {

class Cat {
public:
	Cat();
	virtual ~Cat();
	void speak();
};

Cat::Cat() {
	cout << "Cat created" << endl;
}

Cat::~Cat() {
	cout << "Cat destroyed" << endl;
}

void Cat::speak() {
	cout << "Meow" << endl;
}

}  // Namespace cat

#endif
