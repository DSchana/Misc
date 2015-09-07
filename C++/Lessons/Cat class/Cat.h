// Cat.h
#ifndef CAT_H_
#define CAT_H_

#include <iostream>
using namespace std;

class Cat {
public:
	void speak();
	void jump();
};

void Cat::speak() {
	cout << "Meowwwww !!!!!!!!!!!!" << endl;
}

void Cat::jump() {
	cout << "Jumpping" << endl;
}

#endif