// functions.cpp

#include <iostream>
using namespace std;

void showMenu() {
	cout << "1. Search" << endl << "2. Show" << endl << "3. Quit" << endl;
	cout << "Enter selection" << endl;
}

void showSelection(int selection) {
	if (selection == 1) {
		cout << "Searching" << endl;
	} else if (selection == 2) {
		cout << "Showing" << endl;
	} else if (selection == 3) {
		cout << "Quitting" << endl;
	} else {
		cout << "Please select from the menu itmes" << endl;
	}
}

void select() {
	int selection;
	cin >> selection;

	showSelection(selection);
}

int main(int argc, char const *argv[]) {
	showMenu();
	select();

	return 0;
}