// dataMembers.cpp

#include <iostream>
#include "Cat.h"

using namespace std;

int main(int argc, char const *argv[]) {
	Cat jim;
	Cat bob;

	jim.makeHappy();
	jim.speak();

	bob.makeUnhappy();
	bob.speak();

	return 0;
}