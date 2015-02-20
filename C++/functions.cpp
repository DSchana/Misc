// functions.cpp

#include <iostream>

using namespace std;

void showMenu() {
	cout << "1. Code Day" << endl;
	cout << "2. MHacks" << endl;
	cout << "3. Hack Western" << endl;
}

string proccessInput(int choice) {

	if (choice == 1) {
		return "Code Day";
	}
	if (choice == 2) {
		return "MHacks";
	}
	if (choice == 3) {
		return"Hack Western";
	}
	else {
		return "invalid entry";
	}
}

int main() {
	showMenu();

	int choice;

	cout << "choose" << endl;
	cin >> choice;

	cout << proccessInput(choice) << endl;

	return 0;
}