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
	Animal *pAnimal = new Animal[10];

	pAnimal[5].setName("Bob");
	pAnimal[5].speak();

	delete [] pAnimal;

	char *pMem = new char[1000];
	delete [] pMem;

	return 0;
}
