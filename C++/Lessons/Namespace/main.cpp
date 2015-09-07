// main.cpp

#include <iostream>
#include "Cat.h"
#include "Animal.h"

using namespace std;

int main() {
	cats::Cat cat1;
	animal::Cat cat2;

	cat1.speak();
	cat2.speak();

	return 0;
}
