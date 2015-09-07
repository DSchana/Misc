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

Animal *createAnimal() {
	Animal *pAnimal = new Animal();
	pAnimal->setName("Bertie");
	return pAnimal;
}

int main() {
	Animal *pFrog = createAnimal();

	pFrog->speak();

	delete pFrog;

	return 0;
}
