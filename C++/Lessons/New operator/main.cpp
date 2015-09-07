// main.cpp

#include <iostream>

using namespace std;

class Animal {
private:
	string name;

public:
	Animal() {
		cout << "Animal created." << endl;
	}

	Animal(const Animal& other): name(other.name) {
		cout << "Animal created by copying." << endl;
	}

	~Animal() {
		cout << "Animal destroyed" << endl;
	}

	void setName(string name) {
		this->name = name;
	}

	void speak() const {
		cout << "My name is: " << name << endl;
	}
};


int main() {
	Animal *pCat1 = new Animal();
	pCat1->setName("Freddy");  // -> used when calling methods of pointer objects
	pCat1->speak();  // -> derferences the pointer before calling method
	delete pCat1;  // deletes the memory in location og pointer

	cout << sizeof(pCat1) << endl;

	return 0;
}
