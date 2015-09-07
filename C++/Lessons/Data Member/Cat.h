#ifndef CAT_H_
#define CAT_H_

#include <iostream>

using namespace std;

class Cat {
private:
	bool happy;

public:
	void speak();
	void makeHappy();
	void makeUnhappy();
};

void Cat::speak() {
	if (happy) {
		cout << "meow" << endl;
	} else {
		cout << "ssssssss..." << endl;
	}
}

void Cat::makeHappy() {
	happy = true;
}

void Cat::makeUnhappy() {
	happy = false;
}

#endif