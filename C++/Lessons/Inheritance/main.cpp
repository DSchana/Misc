// main.cpp

#include <iostream>

using namespace std;

class Animal {
public:
	void speak() { cout << "Grrrrrr" << endl; }
};

class Cat: public Animal {
public:
	void jump() { cout << "Cat jumping" << endl; }
};

class Tiger: public Cat {
public:
	void run() { cout << "Tiger running" << endl; }
};

int main() {
	Animal animal;
	animal.speak();

	Cat cat;
	cat.speak();
	cat.jump();

	Tiger tiger;
	tiger.speak();
	tiger.jump();
	tiger.run();

	return 0;
}
