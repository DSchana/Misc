// dataMembers.cpp

#include <iostream>
#include "Cat.h"

using namespace std;

int main(int argc, char const *argv[]) {
	cout << "Starting program..." << endl;
	
	Cat bob;
	bob.speak();

	cout << "Ending program..." << endl;

	return 0;
	// The cat will be destroyed because the cat only exist in between the nearest pair of curlly brackets.
	// Curly brackets can be added without an if or while loop.
}
