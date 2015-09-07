//main.cpp

#include <iostream>

using namespace std;

void change(double &value) {
	value = 123.4;
}

int main() {
	int value1 = 8;
	int &value2 = value1;
	value2 = 10;

	cout << value1 << endl << value2 << endl;

	double value = 432.1;
	change(value);

	cout << value << endl;

	return 0;
}
